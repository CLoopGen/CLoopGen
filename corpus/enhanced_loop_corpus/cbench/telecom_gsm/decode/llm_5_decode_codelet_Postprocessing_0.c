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
    for (k = 160; k--; s++) {
        tmp = (((((longword)(msr) * (longword)(28180) + 16384)) >> (15)));
        ltmp = (longword)(*s) + (longword)(tmp);
        if (ltmp >= -32768 && ltmp <= 32767) {
            msr = ltmp;
        } else {
            msr = (ltmp > 0) ? 32767 : -32768;
        }
        ltmp = (longword)(msr) + (longword)(msr);
        if (ltmp < -32768 || ltmp > 32767) {
            ltmp = (ltmp > 0) ? 32767 : -32768;
        }
        *s = ltmp & 65528;
    }
}
