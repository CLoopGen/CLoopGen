#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k <= 159; k++) {
    if (s[k] == 0) {
        s[k] = 0;
        continue;
    }
    s[k] = (((((longword)(s[k]) * (longword)(16384 >> (2 - 1)) + 16384)) >> (15)));
}
}
