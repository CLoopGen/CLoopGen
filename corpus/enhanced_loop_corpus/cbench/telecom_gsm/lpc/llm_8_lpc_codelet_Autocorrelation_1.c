#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 79; k++) {
        longword temp1 = (longword)(s[k]) * 16384;
        longword temp2 = temp1 + 16384;
        s[k] = (word)(temp2 >> 15);
        s[k + 80] = (word)(temp2 >> 15);
    }
}
