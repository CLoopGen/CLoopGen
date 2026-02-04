#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 temp = 0;
    for (i = (1L << 5) * (1L << 5) * (1L << 5); i-- > 0;) {
        temp += *ptr;       // Introduce RAW dependency: use current *ptr before overwrite
        *ptr++ = temp;      // WAW and WAR: write depends on prior write via temp
        temp ^= 1;          // Break full dependence by varying written value
    }
}
