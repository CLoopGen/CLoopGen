#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *out;
extern INTFLOAT *saved;
extern INTFLOAT *buf;
extern int i;
extern  int n;
extern  int n2;
extern  int n4;
extern  INTFLOAT * window;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n2 > 0) {
        int i = 0;
        for (; i < n2 - 3; i += 4) {
            out[n4 + i]     = (int)(((int64_t)(buf[i]) * (window[i + n2 - n4]) + 1073741824) >> 31) + 
                                (int)(((int64_t)(-saved[n - 1 - i]) * (window[i + n2 + n - n4]) + 1073741824) >> 31) + 
                                (int)(((int64_t)(-saved[n + i]) * (window[i + n2 + 2 * n - n4]) + 1073741824) >> 31) + 
                                (int)(((int64_t)(saved[2 * n + n - 1 - i]) * (window[i + n2 + 3 * n - n4]) + 1073741824) >> 31);
            out[n4 + i + 1] = (int)(((int64_t)(buf[i + 1]) * (window[i + 1 + n2 - n4]) + 1073741824) >> 31) + 
                                (int)(((int64_t)(-saved[n - 1 - (i + 1)]) * (window[i + 1 + n2 + n - n4]) + 1073741824) >> 31) + 
                                (int)(((int64_t)(-saved[n + (i + 1)]) * (window[i + 1 + n2 + 2 * n - n4]) + 1073741824) >> 31) + 
                                (int)(((int64_t)(saved[2 * n + n - 1 - (i + 1)]) * (window[i + 1 + n2 + 3 * n - n4]) + 1073741824) >> 31);
            out[n4 + i + 2] = (int)(((int64_t)(buf[i + 2]) * (window[i + 2 + n2 - n4]) + 1073741824) >> 31) + 
                                (int)(((int64_t)(-saved[n - 1 - (i + 2)]) * (window[i + 2 + n2 + n - n4]) + 1073741824) >> 31) + 
                                (int)(((int64_t)(-saved[n + (i + 2)]) * (window[i + 2 + n2 + 2 * n - n4]) + 1073741824) >> 31) + 
                                (int)(((int64_t)(saved[2 * n + n - 1 - (i + 2)]) * (window[i + 2 + n2 + 3 * n - n4]) + 1073741824) >> 31);
            out[n4 + i + 3] = (int)(((int64_t)(buf[i + 3]) * (window[i + 3 + n2 - n4]) + 1073741824) >> 31) + 
                                (int)(((int64_t)(-saved[n - 1 - (i + 3)]) * (window[i + 3 + n2 + n - n4]) + 1073741824) >> 31) + 
                                (int)(((int64_t)(-saved[n + (i + 3)]) * (window[i + 3 + n2 + 2 * n - n4]) + 1073741824) >> 31) + 
                                (int)(((int64_t)(saved[2 * n + n - 1 - (i + 3)]) * (window[i + 3 + n2 + 3 * n - n4]) + 1073741824) >> 31);
        }
        for (; i < n2; i++) {
            out[n4 + i] = (int)(((int64_t)(buf[i]) * (window[i + n2 - n4]) + 1073741824) >> 31) + 
                          (int)(((int64_t)(-saved[n - 1 - i]) * (window[i + n2 + n - n4]) + 1073741824) >> 31) + 
                          (int)(((int64_t)(-saved[n + i]) * (window[i + n2 + 2 * n - n4]) + 1073741824) >> 31) + 
                          (int)(((int64_t)(saved[2 * n + n - 1 - i]) * (window[i + n2 + 3 * n - n4]) + 1073741824) >> 31);
        }
    }
}
