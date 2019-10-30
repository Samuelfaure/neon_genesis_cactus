import Vue from "vue";
import App from "./App.vue";

// Object.defineProperty(Vue.prototype, "$p5", { value: p5 });

Vue.config.productionTip = false;

new Vue({
  render: h => h(App)
}).$mount("#app");
