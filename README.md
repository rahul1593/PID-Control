# PID Controller Project

In this project, I have implemented a basic PID controller for controlling the steering of the car in simulator.

## Reflections

The simulator gives `speed`, `cross-track error` and `steering angle` of the car. The cross-track error is used to control the steering through PID control. Steering angle is used to control the throttle, because speed should be less in between turns. Following code snippet is used to control the throttle:

```c
  throttle = 0.9;
     .
     .
  if(fabs(angle) > 2){
      throttle -= 0.022 * speed;
      throttle  = (speed <= 30)? 0.3 : throttle;
      throttle  = (throttle < -1.0)? -1.0 : throttle;
  }
```



### Propertional


### Integral


### Derivative


