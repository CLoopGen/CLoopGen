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
for (; k_n-- > 0 && i < 4; s++, i++) {  // Reduced outer trip count effect via additional condition, simplified inner loop
    di = *s;
    sav = di;
    for (int j = 0; j < 4; j++) {  // Reduced inner loop iterations and introduced local index
        ui = u[j];
        rpi = rp[j];
        zzz = ((((longword)(rpi) * (longword)(di)) + 16384) >> 15);
        di = (ltmp = (longword)(ui) + (longword)(zzz)) > 32767 ? 32767 : (ltmp < -32768 ? -32768 : ltmp);
        u[j] = sav;
        sav = di;
    }
    *s = di;
}
}
