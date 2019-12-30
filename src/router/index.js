import Vue from "vue";
import Router from "vue-router";
import Placeholder from "@/components/Placeholder";
const SoundCactus = () => import("@/components/SoundCactus");
const SoundExperiment = () => import("@/components/SoundExperiment");

Vue.use(Router);

export default new Router({
  routes: [
    {
      path: "/",
      name: "Placeholder",
      component: Placeholder
    },
    {
      path: "/sound_cactus",
      name: "SoundCactus",
      component: SoundCactus
    },
    {
      path: "/sound_experiment",
      name: "SoundExperiment",
      component: SoundExperiment
    }
  ]
});
