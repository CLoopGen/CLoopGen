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
    // Variant 1: Consecutive memory access pattern by reordering computations and using local stride variables
    // Access pattern modified to improve spatial locality: buf, saved, and window are now accessed with increasing strides
    for (i = n4; i < n2; i++) {
        int idx1 = n2 - 1 - i;
        int idx2 = i - n4;
        int idx3 = i + n2;
        int idx4 = n + n2 - 1 - i;
        int idx5 = 2 * n + n2 + i;

        int widx1 = idx2;
        int widx2 = i + n - n4;
        int widx3 = i + 2 * n - n4;
        int widx4 = i + 3 * n - n4;

        out[idx2] = 
            (int)(((int64_t)(buf[idx1]) * window[widx1] + 1073741824) >> 31) +
            (int)(((int64_t)(saved[idx3]) * window[widx2] + 1073741824) >> 31) +
            (int)(((int64_t)(-saved[idx4]) * window[widx3] + 1073741824) >> 31) +
            (int)(((int64_t)(-saved[idx5]) * window[widx4] + 1073741824) >> 31);
    }
}
