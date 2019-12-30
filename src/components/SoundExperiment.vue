<template>
  <div>
    <h3 class="text-center">Experiment Lambda</h3>
    <v-btn depressed small color="pink accent-1" @click="start">Start</v-btn>
    <div id="canvas"></div>
  </div>
</template>

<script>
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

      s.createCanvas(500, 500);

      s.fill(0, 155, 0);
      s.stroke(0, 0, 0);
      s.strokeWeight(2);
    },
    drawCanvas(s) {
      s.background(255);
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
