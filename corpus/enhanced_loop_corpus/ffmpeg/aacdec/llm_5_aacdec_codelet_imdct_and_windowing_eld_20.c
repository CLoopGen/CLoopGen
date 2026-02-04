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
    for (i = n4; i < n2; i++) {
        int index = i - n4;
        if (index < n / 8) {
            out[index] = (buf[n2 - 1 - i] + saved[i + n2]) * window[i - n4];
        } else if (index < n / 4) {
            out[index] = (-saved[n + n2 - 1 - i] - saved[2 * n + n2 + i]) * window[i + 2 * n - n4];
        } else {
            out[index] = ((buf[n2 - 1 - i]) * (window[i - n4])) + ((saved[i + n2]) * (window[i + n - n4])) + 
                         ((-saved[n + n2 - 1 - i]) * (window[i + 2 * n - n4])) + ((-saved[2 * n + n2 + i]) * (window[i + 3 * n - n4]));
        }
    }
}
