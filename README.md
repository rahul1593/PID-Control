# PID Controller Project

In this project, I have implemented a basic PID controller for controlling the steering of the car in simulator.

This project involves the Term 2 Simulator which can be downloaded <a href="https://github.com/udacity/self-driving-car-sim/releases">here</a>.

__To build the project run the following commands after cloning this repository:__
1. mkdir build
2. cd build
3. cmake ..
4. make
5. ./pid

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
The proportional component sets the response of the controller which is proportional to the error. If error is more, response would be aggressive, else mild. If only proportional constant is used, it would result in oscillations centered around the zero error points in the output. Following link show shows the output of P-controller(lower `Kp` value than used): <a href="https://youtu.be/A37PKPmfj9c">P-controller</a>.

### Integral
The integral component sets the respose for accumulated error over time. This parameter is used to adjust the controller for systematic bias which is consistent throughout the process. Here we do not have any such bias, but it tries to slow the down the response of controller when it is about to reach the zero error position. This helps to keep the car around center of road (zero CTE).

### Derivative
This component takes the rate of change of the error and tries to smooth the response of the system which helps to avoid the overshoot from the desired zero error position. If this value is too large then the response will be too slow and controller might never reach the zero error position. Smaller value of this parameter might result in oscillations in the output. Following link show shows the output of PD-controller: <a href="https://youtu.be/9jqWVUWnVRM">PD-controller</a>.

In PD-controller, it can be seen that car is going near the corners because of slow down of the repsonse from `Kp` due to `Kd`.

Following are the parameter values which were chosen for the controller:

Kp = 0.21

Ki = 0.005

Kd = 1.9/5.1/7.1

These values were chosen after manual tuning.

The Derivative paramter `Kd` is kept different for different `cross-track error` values as show in below code snippet:
```c
  if(fabs(cte) > 0.7){
    if(fabs(cte) > 0.8)
      pid.Kd = 7.1;
    else
      pid.Kd = 5.1;
  } else{
    pid.Kd = 1.9;
  }
```
This helps in smoothing the response of the controller when car gets high error values and avoids sudden turns. If the car has less error and is near center of the road, a lower value of `Kd` is used so that the car remains at the center. Also in between turns, lower value of `Kd` will ensure smooth turning of the car, because if error is small, controller's response will be mild but accurate.

So, after using the above PID parameter values and variable throttle, car manages higher speeds on straight road and slows down near turns.

Following is the the output video:
<a href="https://youtu.be/f1CfLuv2TpU">Output Video</a>.
