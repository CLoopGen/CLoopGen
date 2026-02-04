#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int64_t sysErr[64];
extern int64_t sysErrMax;
extern int64_t err2_matrix[64];
extern int64_t err2_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 8;
for (i = 0; i < 64; i += stride) {
    for (int j = 0; j < stride && (i + j) < 64; j++) {
        int idx = i + j;
        int64_t se = sysErr[idx];
        int64_t em = err2_matrix[idx];
        sysErrMax = (sysErrMax > se) ? ((se >= 0) ? sysErrMax : ((-se) > sysErrMax ? -se : sysErrMax)) : ((se >= 0) ? se : (-se));
        err2_max = (err2_max > em) ? ((em >= 0) ? err2_max : ((-em) > err2_max ? -em : err2_max)) : ((em >= 0) ? em : (-em));
    }
}
}
