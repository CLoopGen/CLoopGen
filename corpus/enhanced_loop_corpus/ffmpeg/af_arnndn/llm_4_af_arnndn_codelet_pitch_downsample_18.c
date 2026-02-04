#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ac[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i <= 4; i++) {
        if (i % 2 == 1) {
            ac[i] -= ac[i] * (0.00800000038F * i) * (0.00800000038F * i);
        }
    }
}
