#include "main.h"
#include <map>
#include "pros/colors.hpp"


pros::Controller master(pros::E_CONTROLLER_MASTER);

int x = 1;
int y = 1;
int key = 1;

std::map<int, pros::Color> colour_map = {
	{1, pros::Color::white},
	{2, pros::Color::red},
	{3, pros::Color::green},
	{4, pros::Color::blue},
	{5, pros::Color::yellow},
	{6, pros::Color::purple},
	{7, pros::Color::orange},
	{8, pros::Color::dark_sea_green},
	{9, pros::Color::light_goldenrod_yellow},
	{10, pros::Color::fire_brick},
	{11, pros::Color::coral},
	{12, pros::Color::thistle},
	// Add more colors as needed
};

std::map<int, std::string> colour_name_map = {
	{1, "white"},
	{2, "red"},
	{3, "green"},
	{4, "blue"},
	{5, "yellow"},
	{6, "purple"},
	{7, "orange"},
	{8, "dark sea green"},
	{9, "light goldenrod yellow"},
	{10, "fire brick"},
	{11, "coral"},
	{12, "thistle"},
	// Add more color names as needed
};

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::screen::set_eraser(pros::Color::white);
	pros::screen::erase();
	pros::screen::set_pen(pros::Color::red);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */



void opcontrol() {
	

	
	
	while (true) {
		if (colour_map.find(key) != colour_map.end()) {
			pros::Color colour = colour_map[key];
			pros::screen::set_eraser(colour);
		} else {
			master.print(0, 0, "Invalid key: %d", key);
		}

		// status = pros::screen::touch_status();

		if (colour_map.find(key) != colour_map.end()) {
			pros::Color colour = colour_map[key];
			pros::screen::set_eraser(colour);
		} else {
			master.print(0, 0, "Invalid key: %d", key);
		}

		pros::delay(20);                               // Run for 20 ms then update
		if (master.get_digital(DIGITAL_UP))
		{
			pros::screen::erase_pixel(x,y);
			y--;
			pros::screen::draw_pixel(x,y);
		}
		else if (master.get_digital(DIGITAL_DOWN))
		{
			pros::screen::erase_pixel(x,y);
			y++;
			pros::screen::draw_pixel(x,y);
		}
		else if (master.get_digital(DIGITAL_LEFT))
		{
			pros::screen::erase_pixel(x,y);
			x--;
			pros::screen::draw_pixel(x,y);
		}
		else if (master.get_digital(DIGITAL_RIGHT))
		{
			pros::screen::erase_pixel(x,y);
			x++;
			pros::screen::draw_pixel(x,y);
		}
		else if (master.get_digital(DIGITAL_A))
		{
			pros::screen::erase();
		}
		else if (master.get_digital_new_press(DIGITAL_R1))	
		{
			key++;
		}
		else if (master.get_digital_new_press(DIGITAL_L1))
		{
			key--;
		}
		if (master.get_analog(ANALOG_LEFT_X) > 25)
		{
			pros::screen::erase_pixel(x,y);
			x++;
			pros::screen::draw_pixel(x,y);
		}
		if (master.get_analog(ANALOG_LEFT_X) < -25)
		{
			pros::screen::erase_pixel(x,y);
			x--;
			pros::screen::draw_pixel(x,y);
		}
		if (master.get_analog(ANALOG_LEFT_Y) > 25)
		{
			pros::screen::erase_pixel(x,y);
			y--;
			pros::screen::draw_pixel(x,y);
		}
		if (master.get_analog(ANALOG_LEFT_Y) < -25)
		{
			pros::screen::erase_pixel(x,y);
			y++;
			pros::screen::draw_pixel(x,y);
		}
		
		
		// pros::screen::set_eraser(colour_map[colour]);
		
	}
}