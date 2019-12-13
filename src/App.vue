<template>
  <div id="app">
    <button @click="startContext">Neon Genesis Cactus</button>
    <router-view />
  </div>
</template>

<script>
export default {
  name: "App",
  methods: {
    startContext() {
      this.$router.push({ path: "sound" });
    }
  }
};
</script>

<style></style>
