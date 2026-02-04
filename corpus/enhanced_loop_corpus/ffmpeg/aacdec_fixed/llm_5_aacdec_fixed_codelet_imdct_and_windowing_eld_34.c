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
    for (i = n4; i < n2; i++) {
        int term1 = 0, term2 = 0, term3 = 0, term4 = 0;
        if (i >= n4 + (n2 - n4) / 2) {
            term1 = (int)(((int64_t)(buf[n2 - 1 - i]) * (window[i - n4]) + 1073741824) >> 31);
            term2 = (int)(((int64_t)(saved[i + n2]) * (window[i + n - n4]) + 1073741824) >> 31);
        }
        if (i < n4 + (n2 - n4) / 2) {
            term3 = (int)(((int64_t)(-saved[n + n2 - 1 - i]) * (window[i + 2 * n - n4]) + 1073741824) >> 31);
            term4 = (int)(((int64_t)(-saved[2 * n + n2 + i]) * (window[i + 3 * n - n4]) + 1073741824) >> 31);
        }
        out[i - n4] = term1 + term2 + term3 + term4;
    }
}
