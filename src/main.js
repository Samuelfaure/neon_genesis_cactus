import Vue from "vue";
import App from "./App.vue";
import VueRouter from "vue-router";
import router from "@/router";

Vue.use(VueRouter);

Vue.config.productionTip = false;

const app = new Vue({ // eslint-disable-line
  router,
  render: h => h(App)
}).$mount("#app");
