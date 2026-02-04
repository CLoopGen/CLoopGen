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
for (i = 0; i < n2; i++) {
    int term1 = 0, term2 = 0, term3 = 0, term4 = 0;
    if (i < n2 / 2) {
        term1 = (int)(((int64_t)(buf[i]) * (window[i + n2 - n4]) + 1073741824) >> 31);
        term2 = (int)(((int64_t)(-saved[n - 1 - i]) * (window[i + n2 + n - n4]) + 1073741824) >> 31);
    }
    if (i >= n2 / 4) {
        term3 = (int)(((int64_t)(-saved[n + i]) * (window[i + n2 + 2 * n - n4]) + 1073741824) >> 31);
    }
    if (i >= n2 / 2) {
        term4 = (int)(((int64_t)(saved[2 * n + n - 1 - i]) * (window[i + n2 + 3 * n - n4]) + 1073741824) >> 31);
    }
    out[n4 + i] = term1 + term2 + term3 + term4;
}
}
