#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned short *p;
extern unsigned short j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short local_j = j;
    for (i = 2; i < (6 + 3); i++) {
        local_j = (local_j ^ *p++) & 0xFFFF;
    }
    j = local_j;
}
