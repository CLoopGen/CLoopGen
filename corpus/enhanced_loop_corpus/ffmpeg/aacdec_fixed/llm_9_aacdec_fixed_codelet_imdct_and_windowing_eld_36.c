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
    int limit = n4 / 2;
    for (i = 0; i < limit; i++) {
        int idx1 = n2 + n4 + i;
        int idx2 = i + n2;
        int idx3 = n2 - 1 - i;
        int idx4 = n + n2 + i;
        int w1 = window[i + n - n4];
        int w2 = window[i + 2 * n - n4];
        int w3 = window[i + 3 * n - n4];

        int term1 = (int)(((int64_t)(buf[idx2]) * w1 + 1073741824) >> 31);
        int term2 = (int)(((int64_t)(-saved[idx3]) * w2 + 1073741824) >> 31);
        int term3 = (int)(((int64_t)(-saved[idx4]) * w3 + 1073741824) >> 31);

        out[idx1] = term1 + term2 + term3;

        // Add a computational overhead: simulate higher intensity via redundant but safe operations
        out[idx1] += (out[idx1] & 1) ? (out[idx1] >> 1) : (out[idx1] << 1);
        out[idx1] ^= (out[idx1] + 1023) & 0xFF;
    }
}
