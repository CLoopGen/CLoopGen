#include <inttypes.h>
#include <string.h>

char line[262144];
char *p;
int i;

void init_vars() {
    // Initialize the line array with a mix of printable and control characters
    // Total size is 256KB to ensure loop runs for measurable time (~0.01 sec)
    for (int idx = 0; idx < sizeof(line) - 1; idx++) {
        if (idx % 128 == 0 && idx > 0) {
            // Insert '#' to potentially break early in some iterations, but not first
            line[idx] = '#';
        } else if (idx % 32 == 0) {
            // Tab character
            line[idx] = 9;
        } else if (idx % 64 == 0) {
            // Delete character
            line[idx] = 127;
        } else if (idx % 16 == 0) {
            // Control characters in range 1-31 excluding tab (9)
            line[idx] = 7; // Bell character
        } else {
            // Printable character, avoid '#' until forced
            line[idx] = 'A' + (idx % 26);
        }
    }
    // Ensure null termination
    line[sizeof(line) - 1] = '\0';

    // Initialize p to beginning of line buffer
    p = line;

    // Initialize i to 0
    i = 0;
}