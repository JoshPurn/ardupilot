#include "mode.h"
#include "Plane.h"

bool ModeCruise::_enter()
{
    plane.cruise.profile_position = 0;
    plane.target_altitude.amsl_cm = 100*plane.g2.profile_top;
    plane.set_profile_target();
    gcs().send_text(MAV_SEVERITY_INFO, "Entering Depth Speed Control Mode");

    return true;
}

void ModeCruise::update()
{
    plane.nav_roll_cd = 0;
    plane.set_profile_target();
    plane.altitude_error_cm = plane.calc_altitude_error_cm();
    plane.calc_nav_pitch();
}

bool ModeCruise::update_target_altitude()
{
    //custom function to ensure target altitude is used.
    plane.set_profile_target();
    return true;
}

