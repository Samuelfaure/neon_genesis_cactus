import Vue from "vue";
import Router from "vue-router";
import PlaceHolder from "@/components/placeholder";
const SoundControls = () => import("@/components/SoundControls");

Vue.use(Router);

export default new Router({
  routes: [
    {
      path: "/",
      name: "placeholder",
      component: PlaceHolder
    },
    {
      path: "/sound",
      name: "soundControls",
      component: SoundControls
    }
  ]
});
