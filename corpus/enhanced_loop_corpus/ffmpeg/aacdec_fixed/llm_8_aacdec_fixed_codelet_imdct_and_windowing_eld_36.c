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
    for (i = 0; i < n4; i += 2) {
        if (i + 1 < n4) {
            out[n2 + n4 + i] = (int)(((int64_t)(buf[i + n2]) * window[i + n - n4] + 1073741824) >> 31) +
                               (int)(((int64_t)(-saved[n2 - 1 - i]) * window[i + 2 * n - n4] + 1073741824) >> 31) +
                               (int)(((int64_t)(-saved[n + n2 + i]) * window[i + 3 * n - n4] + 1073741824) >> 31);
            out[n2 + n4 + i + 1] = (int)(((int64_t)(buf[i + n2 + 1]) * window[i + 1 + n - n4] + 1073741824) >> 31) +
                                   (int)(((int64_t)(-saved[n2 - 1 - (i + 1)]) * window[i + 1 + 2 * n - n4] + 1073741824) >> 31) +
                                   (int)(((int64_t)(-saved[n + n2 + i + 1]) * window[i + 1 + 3 * n - n4] + 1073741824) >> 31);
        } else {
            out[n2 + n4 + i] = (int)(((int64_t)(buf[i + n2]) * window[i + n - n4] + 1073741824) >> 31) +
                               (int)(((int64_t)(-saved[n2 - 1 - i]) * window[i + 2 * n - n4] + 1073741824) >> 31) +
                               (int)(((int64_t)(-saved[n + n2 + i]) * window[i + 3 * n - n4] + 1073741824) >> 31);
        }
    }
}
