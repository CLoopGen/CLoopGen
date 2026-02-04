#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ac[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++) {
        for (int i = 1; i <= 4; i++) {
            ac[i] -= ac[i] * (0.00800000038F * i) * (0.00800000038F * i);
        }
    }
}
