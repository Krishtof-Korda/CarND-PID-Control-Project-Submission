#include "PID.h"
#include <math.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;
  p_error = 0;
  d_error = 0;
  i_error = 0;
  //err = 0; // twiddle attempt
  
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error; // previous cte minus current cte for differential gain
  p_error = cte; // previous cte for proportional gain
  i_error += cte; // sum of all cte for integral gain
  //err += pow(cte, 2); // tried to use this for twiddle but failed
}

double PID::TotalError() {
  return Kp * p_error + Kd * d_error + Ki * i_error;
}

double PID::Normalize(double steer_value){
  return atan2(sin(steer_value), cos(steer_value)) / M_PI;
}


