
# Controls-Simulations

This is where we design and tune our control system and evaluate how it performs on a mathematical model of our AUV using MATLAB Simulink simulations. 

### Get Started
This repo is in the form of a Simulink project, and requires MATLAB 2019 to correctly operate. To get started, clone this repo into your MATLAB path (folder called MATLAB created when you install MATLAB on your machine) and click the `Subbots_controller.prj`file within the MATLAB application. This will bring up a Project pane in the application where you are able to open and run the models.

### Params
In this folder are the parameter scripts for the control system corresponding to the version of the AUV given by the year in the script's name. When you open up the Simulink project, the current parameter script is run which populates the MATLAB workbench with the parameters which then can be used in the Simulink models.

### Systems
This folder contains the systems that can be run/exported, it contains 3 main systems.
##### control_system.slx
This is the control system that is exported to C++ code that can be used by our ROS system. You can use the embedded coder Simulink app to export the code, which will package the exported system into a zip file found in the `Build` folder. (Note: make sure that all the PID blocks are set to discrete, this has to be done for the exporting process to work, but after doing this, you need to set the blocks back to continuous for the simulations to work)

##### ideal_simulation.slx
This is the ideal simulator which tests our control system under the assumption that we can produce the exact desired thrust/torque given by the controller. The control system is evaluated on `auv_model.slx`, which is our mathematical model of our AUV.

##### real_simulation.slx
This is the real life simulator which attempts to best model the control system according to the mechanical/electrical constraints of our AUV, and also errors in our modelling. It also tests the outputs of `thrust_allocation.slx` which is the block that converts thrust to PWM signals, and is used in our actual control system. The control system is again evaluated on `auv_model.slx`, however this time we add error to the model's outputs to simulate inaccuracies.
