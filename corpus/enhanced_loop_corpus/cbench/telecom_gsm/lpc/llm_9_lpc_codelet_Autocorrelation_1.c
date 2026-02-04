#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 159; k += 2) {
        longword val1 = (longword)(s[k]) * 16384;
        longword val2 = (longword)(s[k + 1]) * 16384;
        s[k] = (word)(((val1 + 16384) >> 15));
        s[k + 1] = (word)(((val2 + 16384) >> 15));
    }
}
