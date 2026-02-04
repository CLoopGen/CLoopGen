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
    for (int j = 0; j < n4; j += 2) {
        for (int i = j; i < j + 2 && i < n4; i++) {
            out[n2 + n4 + i] = ((buf[i + n2]) * (window[i + n - n4])) + 
                               ((-saved[n2 - 1 - i]) * (window[i + 2 * n - n4])) + 
                               ((-saved[n + n2 + i]) * (window[i + 3 * n - n4]));
        }
    }
}
