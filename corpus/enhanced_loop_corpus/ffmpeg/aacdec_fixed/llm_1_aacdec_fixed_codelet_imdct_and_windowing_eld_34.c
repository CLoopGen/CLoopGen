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
    for (i = n4; i < n2; i += 2) {
        for (int k = 0; k < 2 && (i + k) < n2; k++) {
            int idx = i + k;
            out[idx - n4] = (int)(((int64_t)(buf[n2 - 1 - idx]) * (window[idx - n4]) + 1073741824) >> 31) + 
                            (int)(((int64_t)(saved[idx + n2]) * (window[idx + n - n4]) + 1073741824) >> 31) + 
                            (int)(((int64_t)(-saved[n + n2 - 1 - idx]) * (window[idx + 2 * n - n4]) + 1073741824) >> 31) + 
                            (int)(((int64_t)(-saved[2 * n + n2 + idx]) * (window[idx + 3 * n - n4]) + 1073741824) >> 31);
        }
    }
}
