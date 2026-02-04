#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 0; k <= 159; k++)
    s[k] = (((((longword)(s[k]) * (longword)(16384 >> (3 - 1)) + 16384)) >> (15)));

}
