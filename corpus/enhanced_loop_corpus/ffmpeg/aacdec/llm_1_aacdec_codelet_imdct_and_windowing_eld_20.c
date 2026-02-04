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
    for (int k = 0; k < (n2 - n4); k += 2) {
        int i1 = k + n4;
        int i2 = i1 + 1;

        out[i1 - n4] = ((buf[n2 - 1 - i1]) * (window[i1 - n4])) + 
                       ((saved[i1 + n2]) * (window[i1 + n - n4])) + 
                       ((-saved[n + n2 - 1 - i1]) * (window[i1 + 2 * n - n4])) + 
                       ((-saved[2 * n + n2 + i1]) * (window[i1 + 3 * n - n4]));

        if (i2 < n2) {
            out[i2 - n4] = ((buf[n2 - 1 - i2]) * (window[i2 - n4])) + 
                           ((saved[i2 + n2]) * (window[i2 + n - n4])) + 
                           ((-saved[n + n2 - 1 - i2]) * (window[i2 + 2 * n - n4])) + 
                           ((-saved[2 * n + n2 + i2]) * (window[i2 + 3 * n - n4]));
        }
    }
}
