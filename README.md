# Helicopter Model Identification
## Final Outcome of the Project:

<p align="center"> <img src="https://github.com/JakubZasadni/HelicopterModelIdentification/blob/main/HelicopterModelTPI/PNG/Heli.gif.gif" alt="c" width="auto" height="auto"/> </a>


The aim of the project was to identify the key dynamic and static parameters of the system represented by the helicopter model, such as thrust and damping, and to test the effectiveness of the LQR controller in stabilizing the system. Additionally, the goal was to implement a Kalman filter to improve state estimation in the presence of measurement noise. A crucial aspect of the project was also to understand the impact of the cost matrix parameters of the controller on the dynamics and stability of the control system.

The object was controlled by a single propeller. The biggest challenge was the fact that the helicopter is a nonlinear model. The helicopter was controlled to maintain a horizontal position, but it is also possible to set a different angle by modifying a parameter in "regulator.m" within the "get_eqpoint" function.

### Model Description:
The helicopter model is based on an aerodynamic system known as the "Two Rotor Aerodynamical System" (TRAS). The system includes a beam that can move in the vertical plane, driven by an electric motor. The main variables describing the system's dynamics are:
- Beam deflection angle,
- Rotor's rotational speed.

### Research Setup:
The research setup consisted of:
- A helicopter model featuring a rotor driven by an electric motor.
- Sensors measuring rotational speed and deflection angle.
- A control system integrated with MATLAB/Simulink.

### Final Version of the Model with the LQR Controller:

<p align="center"> <img src="https://github.com/JakubZasadni/-HELICOPTER-MODEL-IDENTIFICATION/blob/main/HelicopterModelTPI/PNG/Simulink.png" alt="c" width="auto" height="auto"/> </a>

### University: AGH University of Krakow
### Course: Technological processes identification
### Field of study: Automatic Control and Robotics
### Organisational unit: Faculty of Electrical Engineering, Automatics, Computer Science and Biomedical Engineering

