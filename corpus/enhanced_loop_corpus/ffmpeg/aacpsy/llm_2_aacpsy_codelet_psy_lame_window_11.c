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
for (i = 1; i < 8 + 1; i++) {
    const int idx_prev = (i - 1);
    const int idx_curr = i;
    const float u = energy_short[idx_prev];
    const float v = energy_short[idx_curr];
    const float m = ((u) > (v) ? (u) : (v));
    if (m < 40000) {
        if (u < 1.70000005F * v && v < 1.70000005F * u) {
            if (i == 1 && attacks[0] < attacks[idx_curr])
                attacks[0] = 0;
            attacks[idx_curr] = 0;
        }
    }
    att_sum += attacks[idx_curr];
}
}
