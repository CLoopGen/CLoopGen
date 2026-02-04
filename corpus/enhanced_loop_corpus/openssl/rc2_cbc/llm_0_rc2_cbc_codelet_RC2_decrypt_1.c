#include <stdio.h>

#include <inttypes.h>

typedef unsigned int RC2_INT;

extern int i;
extern int n;
extern RC2_INT *p0;
extern RC2_INT *p1;
extern RC2_INT x0;
extern RC2_INT x1;
extern RC2_INT x2;
extern RC2_INT x3;
extern RC2_INT t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (;;) {
            t = ((x3 << 11) | (x3 >> 5)) & 65535;
            x3 = (t - (x0 & ~x2) - (x1 & x2) - *(p0--)) & 65535;
            t = ((x2 << 13) | (x2 >> 3)) & 65535;
            x2 = (t - (x3 & ~x1) - (x0 & x1) - *(p0--)) & 65535;
            t = ((x1 << 14) | (x1 >> 2)) & 65535;
            x1 = (t - (x2 & ~x0) - (x3 & x0) - *(p0--)) & 65535;
            t = ((x0 << 15) | (x0 >> 1)) & 65535;
            x0 = (t - (x1 & ~x3) - (x2 & x3) - *(p0--)) & 65535;
            if (--i == 0) {
                if (--n == 0)
                    break;
                i = (n == 2) ? 6 : 5;
                x3 = (x3 - p1[x2 & 63]) & 65535;
                x2 = (x2 - p1[x1 & 63]) & 65535;
                x1 = (x1 - p1[x0 & 63]) & 65535;
                x0 = (x0 - p1[x3 & 63]) & 65535;
            }
        }
    }
}
