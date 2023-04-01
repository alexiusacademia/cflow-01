#include <stdio.h>
#include <math.h>

void welcome_message()
{
    printf("Welcome to CFlow, a program written in C to calculate\nwater depth on a rectangular channel section for open channel flow.\n\n");
}

struct RectangularChannel
{
    float base_width;
    float water_depth;
    float discharge;
    float channel_slope;
    float n_manning;

    float w_perimeter; // Calculated wetted perimeter
    float f_area;      // Calculated flow area
    float h_radius;    // Hydraulic radius
    float a_velocity;  // Average velocity
};

int main()
{
    struct RectangularChannel rc;

    printf("Enter discharge (cms): ");
    scanf("%f", &rc.discharge);
    printf("Enter Manning\'s roughness coefficient: ");
    scanf("%f", &rc.n_manning);
    printf("Enter channel slope (m/m): ");
    scanf("%f", &rc.channel_slope);
    printf("Enter base width (m): ");
    scanf("%f", &rc.base_width);

    float trial_discharge = 0;       // Used for trial and error calculation to compare with the discharge input
    const float increment = 0.00001; // Increment for the trial of water depth each loop
    rc.water_depth = 0;              // Reset to zero

    long long milliseconds;

    while (trial_discharge < rc.discharge)
    {
        rc.w_perimeter = rc.base_width + (2 * rc.water_depth);
        rc.f_area = rc.base_width * rc.water_depth;
        rc.h_radius = rc.f_area / rc.w_perimeter;
        rc.a_velocity = (1 / rc.n_manning) * powf(rc.h_radius, (2.0 / 3.0)) * sqrt(rc.channel_slope);
        trial_discharge = rc.a_velocity * rc.f_area;

        rc.water_depth += increment;
    }

    // Display the result
    printf("Water depth of the channel is %.3f m.\n", rc.water_depth);

    return 0;
}