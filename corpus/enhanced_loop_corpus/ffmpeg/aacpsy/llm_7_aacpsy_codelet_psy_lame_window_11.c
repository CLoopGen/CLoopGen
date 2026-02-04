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
    int local_sum = 0;
    int prev_attack = attacks[0];
    for (i = 1; i < 8 + 1; i++) {
        const float u = energy_short[i - 1];
        const float v = energy_short[i];
        const float m = ((u) > (v) ? (u) : (v));
        int current_attack = attacks[i];
        if (m < 40000) {
            if (u < 1.70000005F * v && v < 1.70000005F * u) {
                if (i == 1 && prev_attack < current_attack)
                    prev_attack = 0;
                current_attack = 0;
            }
        }
        attacks[i] = current_attack;
        local_sum += current_attack;
    }
    att_sum += local_sum;
}
