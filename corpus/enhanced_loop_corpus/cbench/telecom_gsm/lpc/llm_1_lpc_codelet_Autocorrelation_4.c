#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j, k;
for (j = 0; j <= 1; j++) {
    for (k = 0; k <= 159; k++) {
        if (j == 1) continue;
        s[k] = (((((longword)(s[k]) * (longword)(16384 >> (4 - 1)) + 16384)) >> (15)));
    }
}
}
