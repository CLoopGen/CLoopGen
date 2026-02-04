#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int *chr;
extern int length;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int factor = 1;
    *chr = 0;
    for (j = 0; j <= length - 2; j++) {
        *chr = *chr + dig[j] * factor;
        factor *= 10;
    }
}
