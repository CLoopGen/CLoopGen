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
    INTFLOAT temp1, temp2, temp3;
    for (i = 0; i < n4; i++) {
        temp1 = buf[i + n2];
        temp2 = saved[n2 - 1 - i];
        temp3 = saved[n + n2 + i];
        out[n2 + n4 + i] = (temp1 * window[i + n - n4]) + ((-temp2) * window[i + 2 * n - n4]) + ((-temp3) * window[i + 3 * n - n4]);
    }
}
