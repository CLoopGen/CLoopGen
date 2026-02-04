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
    out[i - n4] = (int)(((int64_t)(buf[n2 - 1 - i]) * (window[i - n4]) + 1073741824) >> 31) + (int)(((int64_t)(saved[i + n2]) * (window[i + n - n4]) + 1073741824) >> 31);
}
}
