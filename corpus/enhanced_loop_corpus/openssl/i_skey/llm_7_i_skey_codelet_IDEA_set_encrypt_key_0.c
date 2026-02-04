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
    r2 = kf[1];
    r1 = kf[2];
    r0 = kf[3];

    IDEA_INT t0 = ((r2 << 9) | (r1 >> 7)) & 65535;
    IDEA_INT t1 = ((r1 << 9) | (r0 >> 7)) & 65535;

    r1 = kf[4];
    IDEA_INT t2 = ((r0 << 9) | (r1 >> 7)) & 65535;

    r0 = kf[5];
    IDEA_INT t3 = ((r1 << 9) | (r0 >> 7)) & 65535;

    r1 = kf[6];
    IDEA_INT t4 = ((r0 << 9) | (r1 >> 7)) & 65535;

    r0 = kf[7];
    IDEA_INT t5 = ((r1 << 9) | (r0 >> 7)) & 65535;

    *(kt++) = t0;
    *(kt++) = t1;
    *(kt++) = t2;
    *(kt++) = t3;
    *(kt++) = t4;
    *(kt++) = t5;

    if (i >= 5)
        break;

    IDEA_INT t6 = ((r0 << 9) | (kf[0] >> 7)) & 65535;
    IDEA_INT t7 = ((kf[0] << 9) | (r2 >> 7)) & 65535;

    *(kt++) = t6;
    *(kt++) = t7;

    kf += 8;
}
}
