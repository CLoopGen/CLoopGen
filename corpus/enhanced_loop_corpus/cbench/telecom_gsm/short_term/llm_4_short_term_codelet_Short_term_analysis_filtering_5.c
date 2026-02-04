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
word *index_map = (word[]){7, 0, 5, 2, 6, 1, 4, 3};  // Indirect access via index mapping
for (; k_n--; s++) {
    di = sav = *s;
    for (i = 0; i < 8; i++) {
        int mapped_i = index_map[i];  // Use indirect indexing
        ui = u[mapped_i];
        rpi = rp[mapped_i];
        u[mapped_i] = sav;
        zzz = (((((longword)(rpi) * (longword)(di) + 16384)) >> (15)));
        sav = ((ulongword)((ltmp = (longword)(ui) + (longword)(zzz)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
        zzz = (((((longword)(rpi) * (longword)(ui) + 16384)) >> (15)));
        di = ((ulongword)((ltmp = (longword)(di) + (longword)(zzz)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
    }
    *s = di;
}
}
