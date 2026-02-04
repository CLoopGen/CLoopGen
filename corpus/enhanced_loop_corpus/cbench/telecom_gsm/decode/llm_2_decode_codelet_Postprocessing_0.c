#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

typedef unsigned long ulongword;

extern word *s;
extern int k;
extern word msr;
extern longword ltmp;
extern word tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 160; k--; s += 2) {
        word* current_s = s;
        if ((char*)current_s >= (char*)s && k >= 0) {
            tmp = (((((longword)(msr) * (longword)(28180) + 16384)) >> (15)));
            msr = ((ulongword)((ltmp = (longword)(*current_s) + (longword)(tmp)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
            *current_s = ((ulongword)((ltmp = (longword)(msr) + (longword)(msr)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp) & 65528;
        }
    }
}
