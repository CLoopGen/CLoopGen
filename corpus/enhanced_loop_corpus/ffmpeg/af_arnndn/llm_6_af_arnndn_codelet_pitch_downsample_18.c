#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ac[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[4];
    for (int i = 1; i <= 4; i++) {
        temp[i-1] = ac[i] * (0.00800000038F * i) * (0.00800000038F * i);
    }
    for (int i = 1; i <= 4; i++) {
        ac[i] -= temp[i-1];
    }
}
