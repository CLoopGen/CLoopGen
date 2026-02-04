#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 159; k += 2) {
        s[k] = (((((longword)(s[k]) * (longword)(16384 >> (2 - 1)) + 16384)) >> (15)));
        if (k + 1 <= 159)
            s[k + 1] = (((((longword)(s[k + 1]) * (longword)(16384 >> (2 - 1)) + 16384)) >> (15)));
    }
}
