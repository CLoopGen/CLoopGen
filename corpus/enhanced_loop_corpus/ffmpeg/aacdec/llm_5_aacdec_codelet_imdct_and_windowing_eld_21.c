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
        INTFLOAT term1 = 0.0f, term2 = 0.0f, term3 = 0.0f, term4 = 0.0f;
        int index1 = i + n2 - n4;
        int index2 = i + n2 + n - n4;
        int index3 = i + n2 + 2 * n - n4;
        int index4 = i + n2 + 3 * n - n4;

        if (index1 >= 0 && index1 < n2) {
            term1 = buf[i] * window[index1];
        }
        if (n - 1 - i >= 0 && index2 >= 0 && index2 < n2) {
            term2 = (-saved[n - 1 - i]) * window[index2];
        }
        if (n + i < n * 3 && index3 >= 0 && index3 < n2) {
            term3 = (-saved[n + i]) * window[index3];
        }
        if (2 * n + n - 1 - i >= 0 && index4 >= 0 && index4 < n2) {
            term4 = saved[2 * n + n - 1 - i] * window[index4];
        }

        out[n4 + i] = term1 + term2 + term3 + term4;
    }
}
