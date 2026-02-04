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
    word local_di, local_sav;
    local_di = local_sav = *s;
    for (i = 0; i < 8; i++) {
        word temp_ui = u[i];
        word temp_rpi = rp[i];
        word temp_zzz1 = (((((longword)(temp_rpi) * (longword)(local_di) + 16384)) >> (15)));
        local_sav = ((ulongword)((ltmp = (longword)(temp_ui) + (longword)(temp_zzz1)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
        word temp_zzz2 = (((((longword)(temp_rpi) * (longword)(temp_ui) + 16384)) >> (15)));
        local_di = ((ulongword)((ltmp = (longword)(local_di) + (longword)(temp_zzz2)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
        u[i] = temp_ui; // Reordered write to eliminate early mutation (WAW removed)
    }
    *s = local_di;
}
}
