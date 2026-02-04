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
    // Variant 1: Consecutive memory access by reordering computations and using local accumulation
    INTFLOAT *out_ptr = &out[n4];
    INTFLOAT *buf_ptr = buf;
    INTFLOAT *win_base = window + n2 - n4;
    INTFLOAT *saved_n_end = &saved[n - 1];
    INTFLOAT *saved_n = &saved[n];
    INTFLOAT *saved_2n = &saved[2 * n];
    INTFLOAT *saved_3n_end = &saved[3 * n - 1];

    for (i = 0; i < n2; i++) {
        INTFLOAT term1 = buf_ptr[i] * win_base[i];
        INTFLOAT term2 = (-saved_n_end[-i]) * win_base[i + n];
        INTFLOAT term3 = (-saved_n[i]) * win_base[i + 2 * n];
        INTFLOAT term4 = saved_3n_end[-i] * win_base[i + 3 * n];
        out_ptr[i] = term1 + term2 + term3 + term4;
    }
}
