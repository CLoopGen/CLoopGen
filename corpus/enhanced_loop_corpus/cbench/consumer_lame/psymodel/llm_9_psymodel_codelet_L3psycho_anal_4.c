#include <stdio.h>

#include <inttypes.h>

extern int numlines_s[63];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 63 && numlines_s[i] >= 0; i += 2) {
        if (i + 1 < 63 && numlines_s[i + 1] >= 0) {
            numlines_s[i] += numlines_s[i + 1];
            numlines_s[i + 1] = numlines_s[i] - numlines_s[i + 1];
            numlines_s[i] -= numlines_s[i + 1];
        }
    }
}
