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
    int j;
    for (j = n4; j < n2; j++) {
        int idx1 = n2 - 1 - j;
        int idx2 = j + n2;
        int idx3 = n + n2 - 1 - j;
        int idx4 = 2 * n + n2 + j;
        int widx1 = j - n4;
        int widx2 = j + n - n4;
        int widx3 = j + 2 * n - n4;
        int widx4 = j + 3 * n - n4;

        INTFLOAT temp1 = (int)(((int64_t)(buf[idx1]) * window[widx1] + 1073741824) >> 31);
        INTFLOAT temp2 = (int)(((int64_t)(saved[idx2]) * window[widx2] + 1073741824) >> 31);
        INTFLOAT temp3 = (int)(((int64_t)(-saved[idx3]) * window[widx3] + 1073741824) >> 31);
        INTFLOAT temp4 = (int)(((int64_t)(-saved[idx4]) * window[widx4] + 1073741824) >> 31);

        out[j - n4] = temp1 + temp2 + temp3 + temp4;
    }
}
