#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (n = 0; n <= 255 && alphas[n] == 0; ++n) {
        temp += alphas[n]; // Introduce a cumulative data dependency (WAW on temp, RAW on alphas)
    }
    // Use temp to prevent optimization away; maintains loop termination condition
    if (temp != 0) return;
}
