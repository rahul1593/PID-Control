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
I've tried to keep the speed of the car above `30mph` all the time. The throttle is altered in proportion to the current speed only if steering angle is above `2 degrees`.

Following is the explanation for PID parameters:
### Proportional
The proportional component sets the response of the controller which is proportional to the error. If error is more, response would be aggressive, else mild. If only proportional constant is used, it would result in oscillations centered around the zero error points in the output.

### Integral
The integral component sets the respose for accumulated error over time. This parameter is used to adjust the controller for systematic bias which is consistent throughout the process. Here we do not have any such bias, but it tries to slow the down the response of controller when it is about to reach the zero error position. This helps to keep the car around center of road(zero CTE).

### Derivative
This component takes the rate of change of the error and tries to smooth the response of the system and avoid the overshoot from the desired zero error position. If this value is too large then the response will be too slow and controller might never reach the zero error position. Smalle value of this parameter might result in oscillations in the output.

Following are the parameter values which were chosen for the controller:
Kp = 0.21
Ki = 0.005
Kd = 1.9 (1.9/5.1/7.1)
