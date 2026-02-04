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
for (i = 0; i < n; i += 2) {
    int idx1 = n4 + i;
    int idx2 = n4 + i + 1;

    out[idx1] = (buf[i] * window[i + n2 - n4]) + 
                (-saved[n - 1 - i] * window[i + n2 + n - n4]);

    if (i + 1 < n) {
        out[idx2] = (buf[i+1] * window[i + 1 + n2 - n4]) + 
                    (-saved[n - 1 - (i+1)] * window[i + 1 + n2 + n - n4]);
    }
}
}
