#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned short *p;
extern unsigned short j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short indices[] = {0, 1, 2, 3, 4};
    for (i = 2; i < (6 + 3); i++) {
        j |= p[indices[i - 2]];
    }
}
