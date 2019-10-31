<template>
  <div>
    <button @click="start">Start</button>
    <button @click="resume">Resume</button>
    <p>Level : {{ level }}</p>
    <p>SmoothedLevel : {{ level }}</p>
    <p>Radius : {{ radius }}</p>
    <p>Power : {{ power }}</p>
    <div id="canvas"></div>
  </div>
</template>

<script>
import Vue from "vue";
import VueNativeSock from "vue-native-websocket";
import p5 from "p5";
import "p5/lib/addons/p5.sound";

Vue.use(VueNativeSock, "ws://192.168.0.44:80");

export default {
  name: "SoundControls",
  data() {
    return {
      fft: null,
      level: 0,
      radius: 0,
      power: 0,
      myp5: null,
      peakDetect: null
    };
  },
  methods: {
    resume() {
      this.context.resume();
    },
    setupCanvas(s) {
      let mic = new p5.AudioIn();
      mic.start();
      this.context = s.getAudioContext();
      this.fft = new p5.FFT();
      this.fft.setInput(mic);
      this.peakDetect = new p5.PeakDetect();

      s.createCanvas(500, 500);

      s.fill(0, 155, 0);
      s.stroke(0, 0, 0);
      s.strokeWeight(2);
    },
    drawCanvas(s) {
      s.background(255);

      this.fft.analyze();
      this.peakDetect.update(this.fft);

      s.ellipseMode(s.CENTER);

      if (this.peakDetect.isDetected) {
        this.radius = 400;
        this.power = 1020;
      } else {
        this.radius *= 0.95;
        this.power *= 0.95;
      }

      s.ellipse(250, 250, this.radius, this.radius);

      this.$socket.send(this.power);
    },
    start() {
      const vm = this;
      const script = function(s) {
        s.setup = () => {
          vm.setupCanvas(s);
        };
        s.draw = () => {
          vm.drawCanvas(s);
        };
      };
      if (!this.myp5) this.myp5 = new p5(script, "canvas");
    }
  }
};
</script>
