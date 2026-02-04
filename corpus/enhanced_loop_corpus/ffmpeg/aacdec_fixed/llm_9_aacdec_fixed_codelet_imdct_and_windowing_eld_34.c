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
for (i = n4; i < n2 - 2; i++) {
    int idx1 = n2 - 1 - i;
    int idx2 = i + n2;
    int idx3 = n + n2 - 1 - i;
    int idx4 = 2 * n + n2 + i;
    int widx1 = i - n4;
    int widx2 = i + n - n4;
    int widx3 = i + 2 * n - n4;
    int widx4 = i + 3 * n - n4;

    int64_t term1 = (int64_t)(buf[idx1]) * window[widx1];
    int64_t term2 = (int64_t)(saved[idx2]) * window[widx2];
    int64_t term3 = (int64_t)(-saved[idx3]) * window[widx3];
    int64_t term4 = (int64_t)(-saved[idx4]) * window[widx4];

    int sum = ((term1 + 1073741824) >> 31) +
              ((term2 + 1073741824) >> 31) +
              ((term3 + 1073741824) >> 31) +
              ((term4 + 1073741824) >> 31);

    out[i - n4] = sum;

    // Additional computational work to increase intensity
    out[i - n4 + 1] = (int)(((int64_t)(buf[idx1 - 1]) * window[widx1] + 1073741824) >> 31) -
                      (int)(((int64_t)(saved[idx2 + 1]) * window[widx2] + 1073741824) >> 31);
}
}
