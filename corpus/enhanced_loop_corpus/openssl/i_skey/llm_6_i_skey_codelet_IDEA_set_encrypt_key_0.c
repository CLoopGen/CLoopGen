#include <stdio.h>

#include <inttypes.h>

typedef unsigned int IDEA_INT;

extern int i;
extern IDEA_INT *kt;
extern IDEA_INT *kf;
extern IDEA_INT r0;
extern IDEA_INT r1;
extern IDEA_INT r2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 6; i++) {
    IDEA_INT temp_r2 = kf[1];
    IDEA_INT temp_r1 = kf[2];
    IDEA_INT temp_r0 = kf[3];

    *(kt++) = ((temp_r2 << 9) | (temp_r1 >> 7)) & 65535;
    *(kt++) = ((temp_r1 << 9) | (temp_r0 >> 7)) & 65535;

    temp_r2 = kf[4];
    *(kt++) = ((temp_r0 << 9) | (temp_r2 >> 7)) & 65535;

    temp_r0 = kf[5];
    *(kt++) = ((temp_r2 << 9) | (temp_r0 >> 7)) & 65535;

    temp_r2 = kf[6];
    *(kt++) = ((temp_r0 << 9) | (temp_r2 >> 7)) & 65535;

    temp_r0 = kf[7];
    *(kt++) = ((temp_r2 << 9) | (temp_r0 >> 7)) & 65535;

    temp_r1 = kf[0];
    if (i >= 5)
        break;

    *(kt++) = ((temp_r0 << 9) | (temp_r1 >> 7)) & 65535;
    *(kt++) = ((temp_r1 << 9) | (kf[1] >> 7)) & 65535;

    kf += 8;
}
}
