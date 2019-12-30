<template>
  <v-app id="app">
    <v-card flat class="py-12">
      <v-card-text>
        <v-row align="center" justify="center">
          <v-col cols="12">
            <h2 class="text-center">Sound experiences</h2>
          </v-col>
          <v-btn-toggle v-model="toggle_exclusive" rounded>
            <v-btn @click="loadExperience('Placeholder')">
              <v-icon>mdi-stop-circle-outline</v-icon>
            </v-btn>
            <v-btn @click="loadExperience('SoundCactus')">
              <v-icon>mdi-cactus</v-icon>
            </v-btn>
            <v-btn @click="loadExperience('SoundExperiment')">
              <v-icon>mdi-help</v-icon>
            </v-btn>
          </v-btn-toggle>
        </v-row>
      </v-card-text>
    </v-card>
    <router-view />
  </v-app>
</template>

<script>
export default {
  name: "App",
  data() {
    return {
      toggle_exclusive: undefined
    };
  },
  methods: {
    loadExperience(name) {
      this.$router.push({ name });
    }
  }
};
</script>

<style></style>
