<template>
  <div>
    <button @click="start">Start</button>
    <button @click="resume">Resume</button>
    <button @click="log">log</button>
    <p>Level : {{ level }}</p>
    <p>Radius : {{ radius }}</p>
    <div id="canvas"></div>
  </div>
</template>

<script>
import p5 from "p5";
import "p5/lib/addons/p5.sound";

export default {
  name: "SoundControls",
  data() {
    return {
      fft: null,
      level: 0,
      radius: 0,
      mic: null,
      myp5: null
    };
  },
  methods: {
    resume() {
      this.context.resume();
      console.log(this.context);
    },
    log() {
      console.log(this.level);
    },
    setupCanvas(s) {
      this.mic = new p5.AudioIn();
      this.mic.start();
      this.context = s.getAudioContext();
      this.fft = new p5.FFT();
      this.fft.setInput(this.mic);

      s.createCanvas(600, 600);
      // Anti-aliasing
      s.smooth();

      s.fill(0, 155, 0);
      s.stroke(0, 0, 0);
      s.strokeWeight(2);

      s.frameRate(30);
    },
    drawCanvas(s) {
      s.background(255);

      this.fft.analyze();
      this.level = this.fft.getEnergy("bass");

      s.ellipseMode(s.CENTER);
      this.radius = this.calculRadius();
      s.ellipse(300, 300, this.radius, this.radius);
    },
    calculRadius() {
      let radius = this.level * 6 - 800;
      if (radius < 0) radius = 0;
      return radius;
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
