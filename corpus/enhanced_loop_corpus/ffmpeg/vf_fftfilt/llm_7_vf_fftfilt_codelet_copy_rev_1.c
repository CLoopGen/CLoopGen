#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *dest;
extern int w2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FFTSample temp;
    for (int j = 0; j < w2 - i; j += 2) {
        int idx1 = i + j;
        int idx2 = w2 - idx1;
        if (idx1 >= w2 || idx2 < 0) break;
        temp = dest[idx1];
        dest[idx1] = dest[idx2];
        if (idx1 != idx2 && idx2 > idx1)
            dest[idx2] = temp;
    }
}
