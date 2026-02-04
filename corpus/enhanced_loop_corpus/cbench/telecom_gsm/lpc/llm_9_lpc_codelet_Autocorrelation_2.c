#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 255; k++) {
        longword product = (longword)(s[k % 160]) * (16384 >> 1);
        longword sum1 = product + 32768;
        longword sum2 = sum1 + 16384;
        longword shifted = sum2 >> 15;
        s[k % 160] = (word)shifted;
    }
}
