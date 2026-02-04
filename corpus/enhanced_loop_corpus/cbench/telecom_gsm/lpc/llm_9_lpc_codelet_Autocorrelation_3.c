#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 319; k++) {
        longword val = (longword)(s[k % 160]);
        longword scaled = val * 4096;
        longword adjusted = scaled + 8192;
        longword shifted = adjusted >> 14;
        s[k % 160] = (word)(shifted & 0xFFFF);
    }
}
