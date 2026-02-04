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
    for (i = 0; i < n2; i++) {
        temp1 = buf[i];
        temp2 = -saved[n - 1 - i];
        temp3 = -saved[n + i];
        temp4 = saved[2 * n + n - 1 - i];
        out[n4 + i] = (temp1 * window[i + n2 - n4]) + 
                      (temp2 * window[i + n2 + n - n4]) + 
                      (temp3 * window[i + n2 + 2 * n - n4]) + 
                      (temp4 * window[i + n2 + 3 * n - n4]);
    }
}
