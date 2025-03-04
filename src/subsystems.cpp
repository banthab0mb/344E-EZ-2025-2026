#include "subsystems.hpp"
#include "main.h"  // IWYU pragma: keep
#include "pros/misc.h"

// intake control

//pros::MotorGroup wallmech({-14, 13});

void setIntake() {
	// <motor name>.move(a number between -127 and 127);
	if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
		intake.move(-127); 
	} else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		intake.move(127);
	} else {
		intake.move(0);
	}
}

// lady brown control

int armStage = 1; // 1 = Idle, 2 = Loading, 3 = Scoring
bool buttonPressed = false;

void liftControl(int stage) {
    int targetPosition = 0;
    switch (stage) {
        case 1:
            targetPosition = 20; // Idle position 
            break;
        case 2:
            targetPosition = 130; // Loading position 
            break;
        case 3:
            targetPosition = 500; // Scoring position
            break;
    }
    wallmech.move_absolute(targetPosition, 75);
}

void nextState() {
	armStage++;
			if (armStage > 3) armStage = 1;
			liftControl(armStage);
}

 void setWall() {
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
		if (!buttonPressed) {
			armStage++;
			if (armStage > 3) armStage = 1;
			liftControl(armStage);
			buttonPressed = true;
		}
	} else {
		buttonPressed = false;
	}
}

// Pneumatics controls
bool mogomechState = false;
void setMogo() { 
	if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
    mogomechState = !mogomechState; // toggle piston state
    mogomech.set(mogomechState);
	}
}

void autonMogo() {
	mogomechState = !mogomechState; // toggle piston state
    mogomech.set(mogomechState);
}

bool doinkerState = false;
void setdoinker() {
	if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
	doinkerState = !doinkerState;  // toggle piston state
	doinker.set(doinkerState);
	}
}
