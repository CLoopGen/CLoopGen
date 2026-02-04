#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word prev = s[0];
    for (k = 1; k <= 159; k++) {
        word curr = s[k];
        s[k] = (((((longword)(prev) * (longword)(16384 >> (1 - 1)) + 16384)) >> (15)));
        prev = curr;
    }
    if (k > 0)
        s[0] = (((((longword)(prev) * (longword)(16384 >> (1 - 1)) + 16384)) >> (15)));
}
