import Vue from "vue";
import App from "./App.vue";
import p5 from "p5";
import "p5/lib/addons/p5.sound";

Object.defineProperty(Vue.prototype, "$p5", { value: p5 });

Vue.config.productionTip = false;

new Vue({
  render: h => h(App)
}).$mount("#app");
