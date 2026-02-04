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
for (i = 0; i < 3; i++) {
    r2 = kf[1];
    r1 = kf[2];
    r0 = kf[3];
    *(kt++) = ((r2 << 9) | (r1 >> 7)) & 65535;
    *(kt++) = ((r1 << 9) | (r0 >> 7)) & 65535;
    *(kt++) = ((r0 << 9) | (kf[4] >> 7)) & 65535;
    *(kt++) = ((kf[4] << 9) | (kf[5] >> 7)) & 65535;
    *(kt++) = ((kf[5] << 9) | (kf[6] >> 7)) & 65535;
    *(kt++) = ((kf[6] << 9) | (kf[7] >> 7)) & 65535;
    *(kt++) = ((kf[7] << 9) | (kf[0] >> 7)) & 65535;
    *(kt++) = ((kf[0] << 9) | (r2 >> 7)) & 65535;
    kf += 8;
}
}
