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
        INTFLOAT term1 = 0.0f, term2 = 0.0f, term3 = 0.0f;
        if (i >= 0) {
            term1 = (buf[i + n2]) * (window[i + n - n4]);
        }
        if (n2 - 1 - i >= 0) {
            term2 = (-saved[n2 - 1 - i]) * (window[i + 2 * n - n4]);
        }
        if (n + n2 + i < n2 + n4 + n4) { // Assuming bounds check based on plausible max index
            term3 = (-saved[n + n2 + i]) * (window[i + 3 * n - n4]);
        }
        out[n2 + n4 + i] = term1 + term2 + term3;
    }
}
