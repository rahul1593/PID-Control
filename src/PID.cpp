#include "PID.h"
#include <math.h>

using namespace std;

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
  this->d_error = cte - p_error;
  this->p_error = cte;
  //update error history
  /*if(this->cte_history.size() > 20){
    this->i_error -= this->cte_history[0];
    this->cte_history.erase(this->cte_history.begin());
  }
  this->cte_history.push_back(cte);
  */
  this->i_error += cte;
}

double PID::TotalError() {
  return -(Kp * p_error) - (Kd * d_error) - (Ki * i_error);
}
