#include "main.h"

void initialize() {
    pros::Motor motor_ten(10, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {

    pros::Motor motor_ten(10);
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    motor_ten.tare_position();

    float highest_current = 0;

    while(true){
        // motor_ten.set_current_limit(100);
        // motor_ten.move(120 * (master.get_digital(DIGITAL_R1) - master.get_digital(DIGITAL_R2)));
    
        pros::screen::print(TEXT_SMALL, 0, "current: %.3d" "  current_limit: %3d", motor_ten.get_current_draw(), motor_ten.get_current_limit());
        pros::screen::print(TEXT_SMALL, 1, "voltage: %.3d" "  voltage_limit: %3d", (motor_ten.get_voltage()/ 1000), (motor_ten.get_voltage_limit()/ 1000));
        pros::screen::print(TEXT_SMALL, 2, "highest current: %.2f", highest_current);
        pros::screen::print(TEXT_SMALL, 3, "encoder deg: %.2f", motor_ten.get_position());

        if(motor_ten.get_current_draw() > highest_current) highest_current = motor_ten.get_current_draw();

        if(master.get_digital_new_press(DIGITAL_X)){
            if(motor_ten.get_position() < 2500){
                motor_ten.move_relative(5000, 600);
            }

            else if(motor_ten.get_position() > 2500){
                motor_ten.move_relative(-5000, 600);
            }
        }

        pros::delay(5);
    }
	
}