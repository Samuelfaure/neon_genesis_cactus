<template>
  <div>
    <h3 class="text-center">Neon Genesis Cactus</h3>
    <v-btn depressed small color="green accent-1" @click="start">Start</v-btn>
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

Vue.use(VueNativeSock, "ws://192.168.0.17:80", {
  reconnection: true, // (Boolean) whether to reconnect automatically (false)
  reconnectionAttempts: 5, // (Number) number of reconnection attempts before giving up (Infinity),
  reconnectionDelay: 3000 // (Number) how long to initially wait before attempting a new (1000)
}); // 44 for my other module

export default {
  name: "SoundCactus",
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
