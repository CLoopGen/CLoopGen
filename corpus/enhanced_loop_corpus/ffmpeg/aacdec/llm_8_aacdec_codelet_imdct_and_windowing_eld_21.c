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
for (i = 0; i < n4; i++) {
    INTFLOAT term1 = (buf[i] * window[i + n2 - n4]);
    INTFLOAT term2 = (-saved[n - 1 - i] * window[i + n2 + n - n4]);
    out[n4 + i] = term1 + term2;
}
}
