<template>
  <div>
    <h3 class="text-center">Experiment Lambda</h3>
    <v-btn depressed small color="pink accent-1" @click="start">Start</v-btn>
    <v-btn depressed small color="grey accent-1" @click="stop">Stop</v-btn>
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
      script: null
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
    },
    drawCanvas(s) {
      s.background(255);
    },
    start() {
      const vm = this;

      const script = function(s) {
        vm.script = s;

        s.setup = () => {
          vm.setupCanvas(s);
        };
        s.draw = () => {
          vm.drawCanvas(s);
        };
      };
      new p5(script, "canvas");
    },
    stop() {
      this.script.remove();
    }
  }
};
</script>
