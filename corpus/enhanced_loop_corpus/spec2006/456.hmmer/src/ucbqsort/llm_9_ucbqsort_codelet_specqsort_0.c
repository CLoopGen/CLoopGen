#include <stdio.h>

#include <inttypes.h>

extern int qsz;
extern char *base;
extern char c;
extern char *i;
extern char *j;
extern char *hi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = base, hi = base + qsz; i <= hi - stride; i += stride) {
        char temp[4];
        temp[0] = i[0]; temp[1] = i[1]; temp[2] = i[2]; temp[3] = i[3];
        *j++ = temp[3]; *j++ = temp[2]; *j++ = temp[1]; *j++ = temp[0];
    }
    for (; i < hi; i++) {
        *j++ = *i;
    }
}
