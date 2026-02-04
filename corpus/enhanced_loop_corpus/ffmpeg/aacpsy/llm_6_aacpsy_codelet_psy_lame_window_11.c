#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int attacks[9];
extern int i;
extern float energy_short[9];
extern int att_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_attacks[9] = {0};
    for (i = 1; i < 8 + 1; i++) {
        const float u = energy_short[i - 1];
        const float v = energy_short[i];
        const float m = ((u) > (v) ? (u) : (v));
        if (m < 40000) {
            if (u < 1.70000005F * v && v < 1.70000005F * u) {
                if (i == 1 && attacks[0] < attacks[i])
                    temp_attacks[0] = 0;
                temp_attacks[i] = 0;
            } else {
                temp_attacks[i] = attacks[i];
            }
        } else {
            temp_attacks[i] = attacks[i];
        }
    }
    for (i = 1; i < 8 + 1; i++) {
        attacks[i] = temp_attacks[i];
        att_sum += attacks[i];
    }
}
