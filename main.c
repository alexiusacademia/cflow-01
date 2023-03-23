/**
 * Program to practice usage of:
 *  - user input/output
 *  - variables/constant, and
 *  - loop
 */
#include <stdio.h>
#include <math.h>

void welcome_message()
{
    printf("Welcome to CFlow, a program written in C to calculate\nwater depth on a rectangular channel section for open channel flow.\n\n");
}

int main()
{
    welcome_message();

    float water_depth;   // Water depth in meters
    float n_manning;     // Manning's roughness coefficient
    float base_width;    // Channel base width in meters
    float channel_slope; // Channel bed slope on a reach
    float discharge;     // Channel flow in cubic meters per second

    printf("Enter discharge (cms): ");
    scanf("%f", &discharge);
    printf("Enter Manning\'s roughness coefficient: ");
    scanf("%f", &n_manning);
    printf("Enter channel slope (m/m): ");
    scanf("%f", &channel_slope);
    printf("Enter base width (m): ");
    scanf("%f", &base_width);

    float trial_discharge = 0;      // Used for trial and error calculation to compare with the discharge input
    const float increment = 0.0001; // Increment for the trial of water depth each loop
    water_depth = 0;                // Reset to zero

    float w_perimeter; // Calculated wetted perimeter
    float f_area;      // Calculated flow area
    float h_radius;    // Hydraulic radius
    float a_velocity;  // Average velocity

    while (trial_discharge < discharge)
    {
        w_perimeter = base_width + (2 * water_depth);
        f_area = base_width * water_depth;
        h_radius = f_area / w_perimeter;
        a_velocity = (1 / n_manning) * powf(h_radius, (2.0 / 3.0)) * sqrt(channel_slope);
        trial_discharge = a_velocity * f_area;

        water_depth += increment;
    }

    // Display the result
    printf("Water depth of the channel is %.3f m.\n", water_depth);

    return 0;
}