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
        if (i % 2 == 0) {
            out[n2 + n4 + i] = ((buf[i + n2]) * (window[i + n - n4])) + ((-saved[n2 - 1 - i]) * (window[i + 2 * n - n4])) + ((-saved[n + n2 + i]) * (window[i + 3 * n - n4]));
        } else {
            out[n2 + n4 + i] = ((buf[i + n2]) * (window[i + n - n4]));
        }
    }
}
