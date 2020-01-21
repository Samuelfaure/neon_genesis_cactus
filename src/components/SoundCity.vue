<template>
  <div>
    <h3 class="text-center">Experiment Lambda</h3>
    <v-btn depressed small color="pink accent-1" @click="start">Start</v-btn>
    <div id="canvas"></div>
  </div>
</template>

<script>
// Not implemented yet

import p5 from "p5";
import "p5/lib/addons/p5.sound";

export default {
  name: "SoundExperiment",
  data() {
    return {
      fft: null,
      myp5: null
    };
  },
  methods: {
    setupCanvas(s) {
      let mic = new p5.AudioIn();
      mic.start();
      this.context = s.getAudioContext();
      this.fft = new p5.FFT();
      this.fft.setInput(mic);

      s.createCanvas(500, 500, s.WEBGL);

      // s.fill(0, 155, 0);
      // s.stroke(0, 0, 0);
      // s.strokeWeight(2);
    },
    drawCanvas(s) {
      s.background(255);
      // s.rotateX(s.frameCount * 0.01);
      // s.rotateY(s.frameCount * 0.01);
      let i;
      for (i = 0; i < 30; i++) {
        s.translate(-150, 0, (100 + 1) * i);
        s.box(100, 300, 100);
        s.translate(300, 0, 0);
        s.box(100, 300, 100);
        s.translate(-150, 0, 0);
      }
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
