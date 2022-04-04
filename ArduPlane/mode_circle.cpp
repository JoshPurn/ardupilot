#include "mode.h"
#include "Plane.h"

bool ModeCircle::_enter()
{
    plane.circle.profile_position = 0;
    plane.circle.time_max_ms = 15000;
    plane.circle.reached_target_alt = 0;
    plane.target_altitude.amsl_cm = 100*plane.g2.profile_top;
    plane.set_profile_target();
    gcs().send_text(MAV_SEVERITY_INFO, "Entering Depth Profile Mode");

    return true;
}

void ModeCircle::update()
{

    plane.nav_roll_cd = 0;
    plane.set_profile_target();
    plane.altitude_error_cm = plane.calc_altitude_error_cm();
    plane.calc_nav_pitch();
}

bool ModeCircle::update_target_altitude()
{
    //custom function to ensure target altitude is used.
    plane.set_profile_target();
    return true;
}