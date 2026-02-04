#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

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
    INTFLOAT temp1, temp2, temp3, temp4;
    for (i = n4; i < n2; i++) {
        temp1 = buf[n2 - 1 - i] * window[i - n4];
        temp2 = saved[i + n2] * window[i + n - n4];
        temp3 = -saved[n + n2 - 1 - i] * window[i + 2 * n - n4];
        temp4 = -saved[2 * n + n2 + i] * window[i + 3 * n - n4];
        out[i - n4] = temp1 + temp2 + temp3 + temp4;
    }
}
