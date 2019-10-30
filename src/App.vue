<template>
  <div id="app">
    <sound-controls />
  </div>
</template>

<script>
import SoundControls from "./components/SoundControls.vue";

export default {
  name: "App",
  components: {
    SoundControls
  }
};
</script>

<style>
#app {
  font-family: "Avenir", Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
  background-color: grey;
}
</style>
