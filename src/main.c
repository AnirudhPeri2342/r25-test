#include <stdint.h>
#include <stdio.h>
#include <serial.h>
#include <parsing.h>

// Function to map RC channel value to PWM range for Sabertooth and determine direction
int interpolation(uint16_t channel_value, int* direction) {
    // Let's assume the channel value is in the range of 1000 to 2000 (typical for SBUS)
    int pwm_value;

    // Define the midpoint where the robot is stopped
    int midpoint = 1500;

    if (channel_value > midpoint) {
        // Move forward, map the value to a PWM range (e.g., 0-255)
        pwm_value = (channel_value - midpoint) * 255 / (2000 - midpoint);
        *direction = 1; // Set direction to forward
    } else if (channel_value < midpoint) {
        // Move backward, map the value to a PWM range (e.g., 0-255)
        pwm_value = (midpoint - channel_value) * 255 / (midpoint - 1000);
        *direction = -1; // Set direction to backward
    } else {
        // Stop
        pwm_value = 0;
        *direction = 0; // No movement
    }

    return pwm_value;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <SBUS port> <Sabertooth port>\n", argv[0]);
        return 1;
    }

    // Get port names from command-line arguments
    char *port_name_1 = argv[1]; // SBUS 
    char *port_name_2 = argv[2]; // Sabertooth1

    // File pointers for SBUS and Sabertooth
    FILE *sbus; 
    FILE *sabertooth;

    // Buffer for storing SBUS packet
    uint8_t sbus_packet[25]; // SBUS typically has 25-byte packets

    // To store individual RC channel values
    uint16_t *channel;

    // PWM value and direction
    int pwm;
    int direction;

    // Open the SBUS and Sabertooth serial ports
    sbus = open_file(port_name_1, "rb");
    sabertooth = open_file(port_name_2, "w+");

    // Read SBUS data from the RC transmitter
    read_SBUS(sbus_packet, sizeof(sbus_packet), 1, sbus);

    // Parse the SBUS packet to get the channel values
    channel = parse_buffer(sbus_packet);

    // Interpolate the first channel (throttle) to get the PWM value and direction
    pwm = interpolation(channel[0], &direction);

    // Send the direction and speed to Sabertooth
    if (direction == 1) {
        // Forward
        printf("Moving forward with PWM: %d\n", pwm);
        write_to_SB(sabertooth, "F%d", pwm);  // Send forward command
    } else if (direction == -1) {
        // Backward
        printf("Moving backward with PWM: %d\n", pwm);
        write_to_SB(sabertooth, "B%d", pwm);  // Send backward command
    } else {
        // Stop
        printf("Stopping\n");
        write_to_SB(sabertooth, "S");  // Send stop command
    }

    // Close the serial ports
    close_file(sbus);
    close_file(sabertooth);

    return 0;
}
