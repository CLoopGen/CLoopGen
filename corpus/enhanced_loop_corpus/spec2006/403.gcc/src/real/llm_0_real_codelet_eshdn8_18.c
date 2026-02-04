#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short newbyt;
extern unsigned short oldbyt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < (6 + 3); i++) {
    for (int j = 0; j < 1; j++) {
        newbyt = *x << 8;
        *x >>= 8;
        *x |= oldbyt;
        oldbyt = newbyt;
        ++x;
    }
}
}
