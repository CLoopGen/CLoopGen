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
    const int indices[] = {1, 2, 3, 4, 5, 6, 7, 0};
    for (i = 0; i < 6; i++) {
        r2 = kf[indices[0]];
        r1 = kf[indices[1]];
        *(kt++) = ((r2 << 9) | (r1 >> 7)) & 65535;
        r0 = kf[indices[2]];
        *(kt++) = ((r1 << 9) | (r0 >> 7)) & 65535;
        r1 = kf[indices[3]];
        *(kt++) = ((r0 << 9) | (r1 >> 7)) & 65535;
        r0 = kf[indices[4]];
        *(kt++) = ((r1 << 9) | (r0 >> 7)) & 65535;
        r1 = kf[indices[5]];
        *(kt++) = ((r0 << 9) | (r1 >> 7)) & 65533;
        r0 = kf[indices[6]];
        *(kt++) = ((r1 << 9) | (r0 >> 7)) & 65535;
        r1 = kf[indices[7]];
        if (i >= 5)
            break;
        *(kt++) = ((r0 << 9) | (r1 >> 7)) & 65535;
        *(kt++) = ((r1 << 9) | (r2 >> 7)) & 65535;
        kf += 8;
    }
}
