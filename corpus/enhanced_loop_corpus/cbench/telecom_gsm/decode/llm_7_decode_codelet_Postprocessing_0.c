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
    word *s_local = s;
    int k_local = 160;
    longword ltmp_cache[4] = {0};
    word msr_prev = msr;

    for (; k_local >= 4; k_local -= 4, s_local += 4) {
        word tmp0 = ((((longword)(msr_prev) * 28180LL + 16384) >> 15));
        ltmp_cache[0] = (longword)(s_local[0]) + tmp0;
        word msr0 = (ulongword)(ltmp_cache[0] - (-32768)) > 65535 ? (ltmp_cache[0] > 0 ? 32767 : -32768) : ltmp_cache[0];
        
        word tmp1 = ((((longword)(msr0) * 28180LL + 16384) >> 15));
        ltmp_cache[1] = (longword)(s_local[1]) + tmp1;
        word msr1 = (ulongword)(ltmp_cache[1] - (-32768)) > 65535 ? (ltmp_cache[1] > 0 ? 32767 : -32768) : ltmp_cache[1];
        
        word tmp2 = ((((longword)(msr1) * 28180LL + 16384) >> 15));
        ltmp_cache[2] = (longword)(s_local[2]) + tmp2;
        word msr2 = (ulongword)(ltmp_cache[2] - (-32768)) > 65535 ? (ltmp_cache[2] > 0 ? 32767 : -32768) : ltmp_cache[2];
        
        word tmp3 = ((((longword)(msr2) * 28180LL + 16384) >> 15));
        ltmp_cache[3] = (longword)(s_local[3]) + tmp3;
        word msr3 = (ulongword)(ltmp_cache[3] - (-32768)) > 65535 ? (ltmp_cache[3] > 0 ? 32767 : -32768) : ltmp_cache[3];

        s_local[0] = (((ulongword)((ltmp_cache[0] = (longword)(msr0) << 1) - (-32768)) > 65535 ? 
                      (ltmp_cache[0] > 0 ? 32767 : -32768) : ltmp_cache[0])) & 65528;
        s_local[1] = (((ulongword)((ltmp_cache[1] = (longword)(msr1) << 1) - (-32768)) > 65535 ? 
                      (ltmp_cache[1] > 0 ? 32767 : -32768) : ltmp_cache[1])) & 65528;
        s_local[2] = (((ulongword)((ltmp_cache[2] = (longword)(msr2) << 1) - (-32768)) > 65535 ? 
                      (ltmp_cache[2] > 0 ? 32767 : -32768) : ltmp_cache[2])) & 65528;
        s_local[3] = (((ulongword)((ltmp_cache[3] = (longword)(msr3) << 1) - (-32768)) > 65535 ? 
                      (ltmp_cache[3] > 0 ? 32767 : -32768) : ltmp_cache[3])) & 65528;

        msr_prev = msr3;
    }

    for (; k_local > 0; k_local--, s_local++) {
        word tmp_val = ((((longword)(msr_prev) * 28180LL + 16384) >> 15));
        longword acc = (longword)(*s_local) + tmp_val;
        msr_prev = (ulongword)(acc - (-32768)) > 65535 ? (acc > 0 ? 32767 : -32768) : acc;
        *s_local = (((ulongword)((acc = (longword)(msr_prev) << 1) - (-32768)) > 65535 ? 
                    (acc > 0 ? 32767 : -32768) : acc)) & 65528;
    }

    msr = msr_prev;
    s = s_local;
}
