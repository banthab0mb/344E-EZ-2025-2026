#pragma once

#include "EZ-Template/api.hpp"  // IWYU pragma: keep
#include "api.h"  // IWYU pragma: keep
#include "pros/motors.hpp"

// Motors, sensors, etc
inline pros::Motor intake(12);
inline pros::Motor lb1(-14);
inline pros::Motor lb2(13);
inline pros::MotorGroup wallmech({lb1.get_port(), lb2.get_port()});
inline ez::Piston mogomech('G');
inline ez::Piston doinker('C');
inline pros::Optical ringsens(8);
inline pros::Rotation lbRotation(15);

// Functions
void setIntake();
void setWall();
void setMogo();
void setdoinker();
void nextState();
void liftControl();
void autonMogo();

extern bool doinkerState;
extern bool mogomechState;

extern bool buttonPressed;
extern int armStage;