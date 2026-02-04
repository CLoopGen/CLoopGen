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
for (i = 0; i < 9; i++) {
    const float u = energy_short[i];
    const float v = (i < 8) ? energy_short[i + 1] : energy_short[i];
    const float m = ((u) > (v) ? (u) : (v));
    if (m < 40000) {
        if (u * 0.588235F < v && v * 0.588235F < u) {
            if (i == 0 && attacks[0] < attacks[i])
                attacks[0] = 0;
            attacks[i] = 0;
        }
    }
    att_sum += attacks[i];
}
}
