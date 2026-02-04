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
    for (k = 80; k--; s += 2) {
        tmp = (((((longword)(msr) * (longword)(28180) + 16384)) >> (15)));
        msr = ((ulongword)((ltmp = (longword)(*s) + (longword)(tmp)) - (-32768)) > 65535 ? (ltmp > 0 ? 32767 : -32768) : ltmp);
        *s = ((ulongword)((ltmp = (longword)(msr) + (longword)(msr)) - (-32768)) > 65535 ? (ltmp > 0 ? 32767 : -32768) : ltmp) & 65528;
    }
}
