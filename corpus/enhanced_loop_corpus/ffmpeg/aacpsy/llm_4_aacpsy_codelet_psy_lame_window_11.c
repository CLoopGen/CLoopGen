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
    const float u = energy_short[i - 1];
    const float v = energy_short[i];
    const float m = ((u) > (v) ? (u) : (v));
    if (m >= 40000) continue;
    if (!(u < 1.70000005F * v && v < 1.70000005F * u)) continue;
    if (i == 1 && attacks[0] < attacks[i])
        attacks[0] = 0;
    attacks[i] = 0;
    att_sum += attacks[i];
}
}
