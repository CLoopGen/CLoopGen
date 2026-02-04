#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

typedef short IDWTELEM;

extern DWTELEM *src;
extern int stride;
extern  int w;
extern  int h;
extern int x;
extern int y;
extern IDWTELEM *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y, x;
    int total = w * h;
    int unroll_factor = 4;
    int remainder = total % unroll_factor;
    
    int* s = (int*)src;
    short* d = (short*)dst;

    for (int k = 0; k < total - remainder; k += unroll_factor) {
        d[k]     = s[k];
        d[k + 1] = s[k + 1];
        d[k + 2] = s[k + 2];
        d[k + 3] = s[k + 3];
    }

    for (int k = total - remainder; k < total; k++) {
        d[k] = s[k];
    }
}
