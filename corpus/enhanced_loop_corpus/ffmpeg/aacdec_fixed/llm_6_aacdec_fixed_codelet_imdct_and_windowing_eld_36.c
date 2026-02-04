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
    for (i = 0; i < n4; i++) {
        INTFLOAT temp1 = buf[i + n2];
        INTFLOAT temp2 = -saved[n2 - 1 - i];
        INTFLOAT temp3 = -saved[n + n2 + i];
        INTFLOAT win1 = window[i + n - n4];
        INTFLOAT win2 = window[i + 2 * n - n4];
        INTFLOAT win3 = window[i + 3 * n - n4];

        int64_t prod1 = (int64_t)temp1 * win1;
        int64_t prod2 = (int64_t)temp2 * win2;
        int64_t prod3 = (int64_t)temp3 * win3;

        int term1 = (prod1 + 1073741824) >> 31;
        int term2 = (prod2 + 1073741824) >> 31;
        int term3 = (prod3 + 1073741824) >> 31;

        out[n2 + n4 + i] = term1 + term2 + term3;
    }
}
