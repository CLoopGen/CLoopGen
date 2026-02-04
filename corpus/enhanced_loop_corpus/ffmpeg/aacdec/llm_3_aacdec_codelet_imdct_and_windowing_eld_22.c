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
    // Variant 2: Reverse Consecutive Access Pattern
    // Change memory access from forward to reverse order
    // This alters spatial locality and may affect cache behavior
    int i;
    for (i = n4 - 1; i >= 0; i--) {
        out[n2 + n4 + i] = ((buf[i + n2]) * (window[i + n - n4])) + 
                           ((-saved[n2 - 1 - i]) * (window[i + 2 * n - n4])) + 
                           ((-saved[n + n2 + i]) * (window[i + 3 * n - n4]));
    }
}
