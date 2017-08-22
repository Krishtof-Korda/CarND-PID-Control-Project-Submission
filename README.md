# Korda's PID Controls Project for Udacity Self-Driving Car Nanodegree

[YouTube Video](https://youtu.be/3RdFmy1HVIs)

[![alt text](https://img.youtube.com/vi/3RdFmy1HVIs/0.jpg)](https://youtu.be/3RdFmy1HVIs)


### This is my submission for the project described below. I implemented a PID controller for the steering of a simulated car given cross-track error information from the simulator. I also setup a cruise control PID for controlling the speed to a given set point. 

### The main focus of the project was tuning the gains Kp, Ki, and Kd for the proportional, integral, and derivative control inputs respectively. I initially had hoped to implement a Twiddle algorithm that we learned in class but I was unable to determine how to implement Twiddle with the web socket messages. I could not figure out how to restart the simulator automatically and keep the best error gains from previous cycles of Twiddle. This is something I can work on for future improvement. 

### I began my search for the proper gains at unity for all, Kp = Ki = Kd = 1. This led to unsurprisingly poor results illustrated in the video below. The steering is erratic and the car is slow since it is always turning left to right rapidly. I suspected that this was due to integral gain being too high.

[YouTube Video](https://youtu.be/Jcn9RCAVQMA)

[![alt text](https://img.youtube.com/vi/Jcn9RCAVQMA/0.jpg)](https://youtu.be/Jcn9RCAVQMA)

### I then tried to remove integral control to see its affect (see video below). It resulted in much better performance but still unstable in the long term, now probably due to high proportional gain.


[YouTube Video](https://youtu.be/1ZOiqiPqEo4)

[![alt text](https://img.youtube.com/vi/1ZOiqiPqEo4/0.jpg)](https://youtu.be/1ZOiqiPqEo4)


### Then I dropped the proportional gain (Kp = 0.1) to reduce instability (see video below). This made the controller marginally stable and had a limit cycle oscillation which I wanted to eliminate. 


[YouTube Video](https://youtu.be/0N598MWOngM)

[![alt text](https://img.youtube.com/vi/0N598MWOngM/0.jpg)](https://youtu.be/0N598MWOngM)


### Now that I could see the affect of each gain, I then spent some good hours tuning each gain until I reached my final result of Kp = .25, Ki = .001, Kd = 12 for steering control. I also implemented a cruise control using the following gain values tuned starting from my steering gains. The throttle gains final result were Kp = .25, Ki = .005, Kd = 1 (see video below). The video is taken on my cell phone since when I tried to do a screen recording it affected the stability of the car, probably by inducing a lag in processing time. 


[YouTube Video](https://youtu.be/3RdFmy1HVIs)

[![alt text](https://img.youtube.com/vi/3RdFmy1HVIs/0.jpg)](https://youtu.be/3RdFmy1HVIs)



### I learned that proportional gains being too high would lead to unstable oscillations. If not enough derivative gain was applied the system would continue to oscillate in a very sickening manner. The integral control was interesting in that it took very small gains to prevent the integral control from creating instabilities. The controller worked fine without any integral control but I added it in just incase there were some biases that I could not see. 



—

# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
