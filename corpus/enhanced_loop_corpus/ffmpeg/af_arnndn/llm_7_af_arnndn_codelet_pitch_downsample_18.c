#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ac[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_ac = ac[1];
    for (int i = 1; i <= 4; i++) {
        float current_ac = ac[i];
        ac[i] -= current_ac * (0.00800000038F * i) * (0.00800000038F * i);
        prev_ac = current_ac;
    }
}
