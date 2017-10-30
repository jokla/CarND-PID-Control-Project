# Describe the effect each of the P, I, D components had in your implementation.

Term P is proportional to the current value of the error. In this case, the error is equal to the distance between the car and the reference trajectory. This term is not enough to get a satisfactory result since that the vehicle will overshoot the target. 
If the proportional gain is too high, the system can become unstable. Instead, if the proportional gain is too low, we will get a less sensitive controller. The proportional gain amplifies the "present" error, with no consideration for future/past errors.


The term D tries to bring to zero the rate of change of error. For this reason, it is called derivative. It helps to avoid the over-shooting previously mentioned. It attempts to predict what the error will be to approach set point more gracefully.


The term I, called Integral,  is the sum of the instantaneous error over time and it is useful to reduce the steady-state error.

# Describe how the final hyperparameters were chosen.

I chose the gains by manual tuning using trial and error. I started with a small value of the proportional gain $Kp$ (keeping the other gains at zero), and I  increased it step by step. The car at this point was following the track with large oscillation (with 'Kp=0.12' ). After, I tried different values for the derivative gain 'Kd' and tested the result on the simulator. I found 'Kd = 1.5' working well. Regarding the integral gain 'Ki', I got better results by setting it to zero. In fact, in the simulator, there is no bias in the steering. 
