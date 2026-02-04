#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *window;
extern int i;
extern int n;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *win = window;
    int idx1, idx2;
    for (i = 0; i < n2; i++) {
        idx1 = n - 1 - i;
        idx2 = i;
        win[idx1] = win[idx2] + win[idx1];  // Introduces RAW: read before write
        win[idx2] = win[idx1] - win[idx2];  // WAR & WAW: rewrites both locations with new dependencies
    }
}
