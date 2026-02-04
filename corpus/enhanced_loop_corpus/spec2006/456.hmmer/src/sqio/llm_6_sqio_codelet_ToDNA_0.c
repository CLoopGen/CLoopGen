#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = seq;
    char prev = '\0';
    for (; *ptr != '\x00'; ptr++) {
        if (*ptr == 'U') {
            *ptr = 'T';
            prev = 'T'; // Introduce artificial RAW/WAW dependency: current update affects next iteration via 'prev'
        }
        else if (*ptr == 'u') {
            *ptr = 't';
            prev = 't';
        }
        // Add loop-carried dependence: each iteration depends on the modification of 'prev' from the prior iteration
        if (prev == 'T' && *(ptr + 1) == 'u') {
            *(ptr + 1) = 't'; // WAW hazard introduced: potential write after write on next character
            ptr++; // Skip next since we modified it already
        }
    }
}
