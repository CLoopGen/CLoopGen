#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

typedef unsigned long ulongword;

extern word *rp;
extern int k_n;
extern word *s;
extern word *u;
extern int i;
extern word di;
extern word zzz;
extern word ui;
extern word sav;
extern word rpi;
extern longword ltmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; k_n--; s++) {
    di = sav = *s;
    for (i = 0; i < 8; i++) {
        ui = u[i];
        rpi = rp[i];
        u[i] = sav;
        zzz = (((((longword)(rpi) * (longword)(di) + 16384)) >> (15)));
        sav = ((ulongword)((ltmp = (longword)(ui) + (longword)(zzz)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
        zzz = (((((longword)(rpi) * (longword)(ui) + 16384)) >> (15)));
        di = ((ulongword)((ltmp = (longword)(di) + (longword)(zzz)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
        if (sav < 0) {
            sav = -sav;  // Ensure sav is non-negative after update
        }
    }
    *s = di;
}
}
