#include <stdio.h>

#include <inttypes.h>

extern float values[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = (19 + 2); i < (19 + 1) * (19 + 1); i += 2) {
        values[i] = 0.0f;
    }
    for (i = (19 + 2) + 1; i < (19 + 1) * (19 + 1); i += 2) {
        values[i] = 0.0f; // Eliminate loop-carried dependency by splitting into independent iterations
    }
}
