#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

typedef unsigned long ulongword;

extern word *rrp;
extern word *v;
extern int i;
extern word sri;
extern word tmp1;
extern word tmp2;
extern longword ltmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i--;) {
        tmp1 = rrp[i];
        tmp2 = v[i];

        if (!(tmp1 == ((-32767) - 1) && tmp2 == ((-32767) - 1))) {
            tmp2 = 65535 & (((longword)tmp1 * (longword)tmp2 + 16384) >> 15);
        } else {
            tmp2 = 32767;
        }

        ltmp = (longword)(sri) - (longword)(tmp2);
        if (ltmp >= 32767) {
            sri = 32767;
        } else if (ltmp <= ((-32767) - 1)) {
            sri = (-32767) - 1;
        } else {
            sri = ltmp;
        }

        if (!(tmp1 == ((-32767) - 1) && sri == ((-32767) - 1))) {
            tmp1 = 65535 & (((longword)tmp1 * (longword)sri + 16384) >> 15);
        } else {
            tmp1 = 32767;
        }

        ltmp = (longword)(v[i]) + (longword)(tmp1);
        if ((ulongword)(ltmp - ((-32767) - 1)) > (32767) - ((-32767) - 1)) {
            v[i + 1] = (ltmp > 0 ? 32767 : ((-32767) - 1));
        } else {
            v[i + 1] = ltmp;
        }
    }
}
