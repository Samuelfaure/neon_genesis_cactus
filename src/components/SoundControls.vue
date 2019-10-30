<template>
  <div>
    <button @click="keypress">Start</button>
    <p>Level : {{ level }}</p>
    <div id="canvas" ref="canvas5"></div>
  </div>
</template>

<script>
import p5 from "p5";
import "p5/lib/addons/p5.sound";

export default {
  name: "SoundControls",
  data() {
    return {
      level: 0,
      mic: null,
      myp5: null
    };
  },
  methods: {
    keypress() {
      const script = function(s) {
        let speed = 2;
        let posX = 0;

        s.setup = () => {
          s.createCanvas(1000, 1000);
          s.ellipse(s.width / 2, s.height / 2, 500, 500);
        };
        s.draw = () => {
          s.background(0);
          const degree = s.frameCount * 3;
          const y = s.sin(s.radians(degree)) * 50;

          s.push();
          s.translate(0, s.height / 2);
          s.ellipse(posX, y, 50, 50);
          s.pop();
          posX += speed;

          if (posX > s.width || posX < 0) {
            speed *= -1;
          }
        };
      };

      this.myp5 = new p5(script, "canvas");
    }
  }
};
</script>

<!-- <style> -->
<!-- .canvas { -->
<!--   background-color: green; -->
<!--   width: 500px; -->
<!--   height: 500px; -->
<!-- } -->
<!-- </style> -->
