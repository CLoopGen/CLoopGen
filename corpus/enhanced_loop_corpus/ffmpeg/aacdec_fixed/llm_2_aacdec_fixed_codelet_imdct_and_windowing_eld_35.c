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
for (i = 0; i < n2; i += 2) {
    int idx1 = i;
    int idx2 = i + n2 - n4;
    int idx3 = n - 1 - i;
    int idx4 = i + n2 + n - n4;
    int idx5 = n + i;
    int idx6 = i + n2 + 2 * n - n4;
    int idx7 = 2 * n + n - 1 - i;
    int idx8 = i + n2 + 3 * n - n4;
    int oidx = n4 + i;

    out[oidx] = (int)(((int64_t)(buf[idx1]) * (window[idx2]) + 1073741824) >> 31) + 
                (int)(((int64_t)(-saved[idx3]) * (window[idx4]) + 1073741824) >> 31) + 
                (int)(((int64_t)(-saved[idx5]) * (window[idx6]) + 1073741824) >> 31) + 
                (int)(((int64_t)(saved[idx7]) * (window[idx8]) + 1073741824) >> 31);

    if (i + 1 < n2) {
        idx1 = i + 1;
        idx2 = i + 1 + n2 - n4;
        idx3 = n - 1 - (i + 1);
        idx4 = i + 1 + n2 + n - n4;
        idx5 = n + i + 1;
        idx6 = i + 1 + n2 + 2 * n - n4;
        idx7 = 2 * n + n - 1 - (i + 1);
        idx8 = i + 1 + n2 + 3 * n - n4;
        oidx = n4 + i + 1;

        out[oidx] = (int)(((int64_t)(buf[idx1]) * (window[idx2]) + 1073741824) >> 31) + 
                    (int)(((int64_t)(-saved[idx3]) * (window[idx4]) + 1073741824) >> 31) + 
                    (int)(((int64_t)(-saved[idx5]) * (window[idx6]) + 1073741824) >> 31) + 
                    (int)(((int64_t)(saved[idx7]) * (window[idx8]) + 1073741824) >> 31);
    }
}
}
