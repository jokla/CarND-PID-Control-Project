#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID(): p_error(0.0), i_error(0.0), d_error(0.0), min_output(-1.0), max_output(+1.0)
{}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_, double min_output_, double max_output_) {
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
    min_output = min_output_;
    max_output = max_output_;
}

void PID::UpdateError(double cte) {
    i_error = cte + i_error;
    d_error = cte - p_error;
    p_error = cte;

}

double PID::TotalError() {
    double result =  -Kp * p_error - Kd * d_error - Ki * i_error;
    if(result >= max_output)
    {
      return max_output;
    }
    else if(result <= min_output)
    {
      return min_output;
    }
    else
    {
      return result;
    }
}

