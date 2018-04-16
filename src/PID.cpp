#include "PID.h"
#include <math.h>

using namespace std;

double weighted_average(std::vector<double> list){
  const int n = list.size();
  int wl = n*(n+1)/2;
  double sm = 0;
  
  for(int i=0; i<n; i++)
    sm += list[i];
  
  return sm/wl;
}

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  //initialize coefficients
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  //initialize error terms
  this->p_error = 0;
  this->i_error = 0;
  this->d_error = 0;
}

void PID::UpdateError(double cte) {
  this->d_error = cte - this->p_error;
  this->p_error = cte;
  this->i_error += cte;
}

double PID::TotalError() {
  return -(Kp * p_error) - (Kd * d_error) - (Ki * i_error);
}
