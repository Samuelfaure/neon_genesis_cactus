<template>
  <div>
    <vue-p5 v-if="record" @setup="setup" @draw="draw"></vue-p5>
    <button @click="start">Start</button>
    <button @click="stop">Stop</button>
    <p>Level : {{ level }}</p>
  </div>
</template>

<script>
import VueP5 from "vue-p5";

export default {
  name: "SoundControls",
  components: {
    "vue-p5": VueP5
  },
  data() {
    return {
      record: false,
      level: 0,
      mic: null
    };
  },
  methods: {
    setup() {
      this.mic = new this.$p5.AudioIn();
      this.mic.start();
    },
    start() {
      this.record = true;
    },
    stop() {
      this.record = false;
    },
    draw() {
      this.level = this.mic.getLevel();
    }
  }
};
</script>

<style lang="scss"></style>
