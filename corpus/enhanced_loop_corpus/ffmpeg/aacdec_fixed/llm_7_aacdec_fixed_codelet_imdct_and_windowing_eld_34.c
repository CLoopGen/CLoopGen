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
    if (n2 <= n4) return;
    out[n4 - n4] = (int)(((int64_t)(buf[n2 - 1 - n4]) * window[0] + 1073741824) >> 31) + 
                   (int)(((int64_t)(saved[n2 + n4]) * window[n4 + n - n4] + 1073741824) >> 31) + 
                   (int)(((int64_t)(-saved[n + n2 - 1 - n4]) * window[n4 + 2 * n - n4] + 1073741824) >> 31) + 
                   (int)(((int64_t)(-saved[2 * n + n2 + n4]) * window[n4 + 3 * n - n4] + 1073741824) >> 31);

    for (i = n4 + 1; i < n2; i++) {
        int prev_offset = i - 1 - n4;
        int curr_offset = i - n4;

        int term1 = (int)(((int64_t)(buf[n2 - 1 - i]) * window[curr_offset] + 1073741824) >> 31);
        int term2 = (int)(((int64_t)(saved[i + n2]) * window[i + n - n4] + 1073741824) >> 31);
        int term3 = (int)(((int64_t)(-saved[n + n2 - 1 - i]) * window[i + 2 * n - n4] + 1073741824) >> 31);
        int term4 = (int)(((int64_t)(-saved[2 * n + n2 + i]) * window[i + 3 * n - n4] + 1073741824) >> 31);

        out[curr_offset] = term1 + term2 + term3 + term4 + out[prev_offset] - out[prev_offset];
    }
}
