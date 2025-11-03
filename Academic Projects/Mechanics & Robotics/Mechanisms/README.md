# Design and Analysis of a four-bar crank-slider mechanism

## Metadata
- **Subject:** IM0241 - Mechanisms
- **Professor:** Juan Andres Gallego Sanchez - jgalleg5@eafit.edu.co
- **Semester:** 2022-1
- **Authors:** 
  - Daniel Hurtado López - dhurtadol@eafit.edu.co
  - Alejandro Arango Giraldo - aarangog2@eafit.edu.co
 
---

## Project Summary

This project focuses on the **design and analysis of a four-bar crank-slider mechanism** through three complementary approaches: **dimensional synthesis**, **numerical analysis**, and **kinematic analysis**. Using **MATLAB** and **Excel**, the dimensional synthesis determines the optimal geometric parameters of the mechanism based on three precision points, applying the **Freudenstein equation** to compute constants and link dimensions. The numerical analysis then solves the **kinematic constraint equations** using iterative methods and the **Jacobian matrix** to determine the slider’s position for different input angles. Finally, the kinematic analysis extends this approach to compute and visualize the **position, velocity, and acceleration** of the slider as functions of time. The results were validated through simulations in **Working Model**, ensuring the designed mechanism performs according to the specified motion requirements.

## Context

Each analysis was developed independently using the following tools:
* MATLAB 9.12.0
* Working Model 2D - Version 5.0.1.31
* Excel

---

## Files in this folder

- **`Kinematic Analysis/`**:
  - **`Kinematic Analysis.pdf`**: Kinematic analysis report.
  - **`Kinematic Analysis Simulation.xlsx`**: Kinematic analysis simulation in Excel.
  - **`Crank_Slider.wm`**: Crank-slider model in Working Model.
  - **`Crank_Slider.m`**: Crank-slider calculations in Matlab.
- **`Numerical Analysis/`**:
  - **`Numerical Analysis.pdf`**: Numerical analysis report.
  - **`Numerical Analysis Simulation.xlsx`**: Numerical analysis simulation in Excel.
  - **`Crank_Slider.wm`**: Crank-slider model in Working Model.
  - **`Crank_Slider.m`**: Crank-slider calculations in Matlab.
- **`Dimensional Synthesis/`**:
  - **`Dimensional Synthesis.pdf`**: Dimensional Synthesis report.
  - **`Dimensional Synthesis Simulation.xlsx`**: Dimensional Synthesis simulation in Excel.
  - **`dimensional_synthesis_model.wm`**: Dimensional Synthesis model in Working Model.
  - **`Dimensional_Synthesis.m`**: Dimensional Synthesis calculations in Matlab.
  - **`NumberSynthesis_M6B1DGL.m`**: Numerical Synthesis calculations in Matlab.
