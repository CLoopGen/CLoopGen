#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char tmpbuf[4096];
extern char *s;
extern I32 len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    len = 0;
    char prev_char = '\0';

    // Introduce loop-carried RAW dependency: current iteration depends on prior modification
    for (; *s && *s != ';'; s++) {
        if (len < sizeof tmpbuf - 1) {  // Leave space for potential use of next char
            tmpbuf[len] = *s;
            // Artificial dependency: modify behavior based on previous input
            if (prev_char == ' ' && *s == ' ') {
                // Collapse double space — introduces state dependence
                len--;  // Rewind, creating a WAW-like correction
            }
            prev_char = *s;
        }
        len++;
    }

    // Final null termination adjustment if needed
    if (len >= sizeof tmpbuf) len = sizeof tmpbuf - 1;
}
