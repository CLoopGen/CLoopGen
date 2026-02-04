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
    int idx = i * 2; // Strided access with step 2
    tmp1 = rrp[idx];
    tmp2 = v[idx];
    tmp2 = (tmp1 == ((-32767) - 1) && tmp2 == ((-32767) - 1) ? (32767) : 65535 & (((longword)tmp1 * (longword)tmp2 + 16384) >> 15));
    sri = ((ltmp = (longword)(sri) - (longword)(tmp2)) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
    tmp1 = (tmp1 == ((-32767) - 1) && sri == ((-32767) - 1) ? (32767) : 65535 & (((longword)tmp1 * (longword)sri + 16384) >> 15));
    v[idx + 2] = ((ulongword)((ltmp = (longword)(v[idx]) + (longword)(tmp1)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
}
}
