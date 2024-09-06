# R-25 Test

<p align="center">
  <img src="https://github.com/teamrudra/r25-test/blob/main/datasheets/rover.jpeg" width="600" height="300"/>

#### Some Instructions
1. You may use any online resources, datasheets, or documentation needed, but be mindful of your time and stay focused on the task.
2. The duration of the test is 90 mins from 5:15pm to 6:45 pm.
3. There will be a MCQ test conducted [here](https://r25.munmap.net)
4. There are 3 tasks in the tests. Complete all of them.
5. In case you are not able to complete all the tasks, do upload the whatever you are able to do.
6. In the `README.md` of your repository include your thought process, places where you got stuck, where you used the help of chatGPT, google or other online resources.
7. Even if you are not able to solve anything. Do fill the readme and what your thought process would have been.
8. Carefully read the instructions to implement the required functionality.
9. Install [mingw(c compiler)](https://www.mingw-w64.org/downloads/#w64devkit) and [git](https://git-scm.com/downloads) if you haven't already done it.
10. After finishing your test, provide the link to your forked repository in the google form provided at the end.
     
### Aim/Objective: You are implementing code to control motors for a rover using data received from an RC transmitter.
## Description
You are implementing code to control a sabrtooth motor driver(we are only trying to control motor 1 using S1 of Sabertooth), connected to drive motors of the rover, using data received from an [RC transmitter](datasheets/transmitter-manual.pdf)(make note that the transmitter is configured to transmit data in extended limits). The data from the transmitter is being recieved by a SBUS reciever module, you can find about the data protocol used [here](https://github.com/bolderflight/sbus/blob/main/README.md). 

### Task 0: Fork the provided repository and ensure it is set to PUBLIC so we can access and assess your work.
### Task 1: Interpolation for Sabertooth.
The motor driver (`Sabertooth 2x60`) in the simplified serial mode (check out the [datasheets](datasheets/sabertooth(2x60).pdf))
Your task is to interpolate a channel value into the format accepted by the motor driver, and make the rover move in forward or backward direction.
### Task 2: Compile and run the code.

#### Code
1. [src/main.c](src/main.c): Code for running the test.
2. [lib/parsing.c](lib/parsing.c): Complete the defined `interpolation` function here.

#### How to Compile & Check your code
(make sure you are in the root directory)   
1. Compile your code by running: `make build`
2. To check if your code is implemented correctly run: `make check`
   
If you are able to compile your code successfully you should see something like this on your screen:

<p align="center">
  <img src="https://github.com/teamrudra/r25-test/blob/main/datasheets/make_check_succesfull.png" width="600" height="300"/>
</p>

4. If your make check was unsuccesfull, you can clean your attempt by running `make clean`, review your implementation and repeat the previous steps.

# Solution
Basically what was needed to be done was a code needed to be written which was in the motor drivers range and moved the robot front or back or stop.
SBUS Port:- Where we recieve signals from RC Transmitter
Sabertooth Port:- Where we send commands to the robots controller
Determining Movement:- If the pwm value crossed a certain level the robot was instructed to move forward and if it dropped below a certain level it would move back.
                       If it was maintained in between the forward and backward range, it would not move.
## Understanding
What i understood from this test was how much more depth there is to coding than simply writing a code executing it and making changes. The setup for ming and git itself showed me a side of coding that i never realised was right there. What i unerstood from the tasks was a slice of how coding would be different from the one we learn in class. Although this definitely had humbled me I peculiarly seem more interested than ever in the domain of coding and programming.

## Thought Process
Upon reading the tasks, I had to search a few things to better understand the given question and how to tackle it. On reading a little i realised the base idea of what was to be done and started figuring out how to set up ming and git. After some time when i finally got it setup I started working on thinking about the code and what I would have to change to achieve the required result. Since we needed to move the robot in 2 directions I comprehended that there was 3 main things I would have to clearly show in the code. The values of pwm for which the machine needs to move forward, back, and stop. After searching a little more and a conversation with chat gpt the code became a little more comprehensive to me which is when I started working on how to write the code. Another hour or so of researching the web and understanding more and more of the task and the given code I think I was finally able to come up with some code that althought doesnt give the correct end result, is something similar to what i should have done.


## Implementation
Describes in 'Thought Process'


# Google Form
[Link to Repo Submission](https://docs.google.com/forms/d/e/1FAIpQLSeKVbm2dqWxwA5lbEkRfzY8KF619mI5ibGs0Cm2e5wrb0hoWQ/viewform)


<p align="center">
  <img src="https://github.com/teamrudra/r25-test/blob/main/datasheets/feynman-simple.jpg" width="600" height="600"/>
</p>
