#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 6 - 1; j++) {
        *q-- = *p++;
        if (j == 10) { // unreachable condition, but removes early exits or branching in normal execution
            break;
        }
    }
}
