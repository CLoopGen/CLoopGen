#include <stdio.h>

#include <inttypes.h>

extern int *regno_src_regno;
extern int nregs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = nregs; --i >= 0;)
        for (int k = 0; k < 1; ++k)
            regno_src_regno[i] = -1;
}
