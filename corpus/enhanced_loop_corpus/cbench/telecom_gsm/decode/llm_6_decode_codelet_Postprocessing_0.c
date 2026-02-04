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



void loop() {
    word *local_s = s;
    word msr_local = msr;
    longword ltmp_local;
    word tmp_local;

    for (k = 160; k--; ) {
        tmp_local = (((((longword)(msr_local) * (longword)(28180) + 16384)) >> 15));
        msr_local = ((ulongword)((ltmp_local = (longword)(*local_s) + (longword)(tmp_local)) - (-32768)) > 65535 ? 
                     (ltmp_local > 0 ? 32767 : -32768) : ltmp_local);
        *local_s = ((ulongword)((ltmp_local = (longword)(msr_local) + (longword)(msr_local)) - (-32768)) > 65535 ? 
                    (ltmp_local > 0 ? 32767 : -32768) : ltmp_local) & 65528;
        local_s++;
    }
    s = local_s;
    msr = msr_local;
}
