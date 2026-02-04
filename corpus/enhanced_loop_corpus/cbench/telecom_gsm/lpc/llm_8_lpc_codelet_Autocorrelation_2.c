#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 79; k += 2) {
        longword temp1 = (longword)(s[k]) * 8192 + 8192;
        s[k] = (word)(temp1 >> 15);
        if (k + 1 <= 159) {
            longword temp2 = (longword)(s[k + 1]) * 8192 + 8192;
            s[k + 1] = (word)(temp2 >> 15);
        }
    }
}
