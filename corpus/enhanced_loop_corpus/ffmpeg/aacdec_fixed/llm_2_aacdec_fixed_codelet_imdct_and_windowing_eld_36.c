#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

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
    // Variant 1: Consecutive memory access with precomputed base pointers and stride of 1
    // Reorganize array accesses to use consecutive loads by shifting base indices
    INTFLOAT *buf_base = &buf[n2];
    INTFLOAT *win1_base = &window[n - n4];
    INTFLOAT *win2_base = &window[2 * n - n4];
    INTFLOAT *win3_base = &window[3 * n - n4];
    INTFLOAT *saved1_base = &saved[n2 - 1];
    INTFLOAT *saved2_base = &saved[n + n2];
    INTFLOAT *out_base = &out[n2 + n4];

    for (i = 0; i < n4; i++) {
        out_base[i] = (int)(((int64_t)(buf_base[i]) * (win1_base[i]) + 1073741824) >> 31) +
                      (int)(((int64_t)(-saved1_base[-i]) * (win2_base[i]) + 1073741824) >> 31) +
                      (int)(((int64_t)(-saved2_base[i]) * (win3_base[i]) + 1073741824) >> 31);
    }
}
