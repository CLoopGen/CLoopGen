#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 79; k += 2) {
        longword temp1 = (longword)(s[k]) * 4096 + 16384;
        s[k] = (word)(temp1 >> 15);
        longword temp2 = (longword)(s[k+1]) * 4096 + 16384;
        s[k+1] = (word)(temp2 >> 15);
    }
}
