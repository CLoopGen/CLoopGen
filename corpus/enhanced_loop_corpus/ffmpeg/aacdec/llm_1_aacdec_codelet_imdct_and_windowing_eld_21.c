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
    for (i = 0; i < n2; i += 2) {
        for (int k = 0; k < 2 && (i + k) < n2; k++) {
            int idx = i + k;
            out[n4 + idx] = ((buf[idx]) * (window[idx + n2 - n4])) + 
                            ((-saved[n - 1 - idx]) * (window[idx + n2 + n - n4])) + 
                            ((-saved[n + idx]) * (window[idx + n2 + 2 * n - n4])) + 
                            ((saved[2 * n + n - 1 - idx]) * (window[idx + n2 + 3 * n - n4]));
        }
    }
}
