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
    for (i = 0; i < n2; i++) {
        if ((i % 2) == 0) {
            out[n4 + i] = ((buf[i]) * (window[i + n2 - n4])) + 
                          ((-saved[n - 1 - i]) * (window[i + n2 + n - n4])) + 
                          ((-saved[n + i]) * (window[i + n2 + 2 * n - n4])) + 
                          ((saved[2 * n + n - 1 - i]) * (window[i + n2 + 3 * n - n4]));
        } else {
            out[n4 + i] = 0.0f;
        }
    }
}
