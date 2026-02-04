#include <stdio.h>

#include <inttypes.h>

extern int *regno_src_regno;
extern int nregs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = nregs * 2;
    for (i = 0; i < limit; i += 2) {
        regno_src_regno[i / 2] = -1;
    }
}
