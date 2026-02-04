#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ac[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 8; i += 2) {
    int idx = i / 2 + 1;
    float factor = 0.00800000038F * idx;
    ac[idx] -= ac[idx] * factor * factor;
}
}
