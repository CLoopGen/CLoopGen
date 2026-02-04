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
        IDEA_INT temp[8];
        for (int j = 0; j < 8; j++) {
            temp[j] = kf[j];
        }
        r2 = temp[1];
        r1 = temp[2];
        *(kt++) = ((r2 << 9) | (r1 >> 7)) & 65535;
        r0 = temp[3];
        *(kt++) = ((r1 << 9) | (r0 >> 7)) & 65535;
        r1 = temp[4];
        *(kt++) = ((r0 << 9) | (r1 >> 7)) & 65535;
        r0 = temp[5];
        *(kt++) = ((r1 << 9) | (r0 >> 7)) & 65535;
        r1 = temp[6];
        *(kt++) = ((r0 << 9) | (r1 >> 7)) & 65535;
        r0 = temp[7];
        *(kt++) = ((r1 << 9) | (r0 >> 7)) & 65535;
        r1 = temp[0];
        if (i >= 5)
            break;
        *(kt++) = ((r0 << 9) | (r1 >> 7)) & 65535;
        *(kt++) = ((r1 << 9) | (r2 >> 7)) & 65535;
        kf += 8;
    }
}
