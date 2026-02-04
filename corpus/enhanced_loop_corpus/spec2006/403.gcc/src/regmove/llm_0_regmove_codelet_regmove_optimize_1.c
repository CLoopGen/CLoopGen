#include <stdio.h>

#include <inttypes.h>

extern int *regno_src_regno;
extern int nregs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; ++j)
        for (i = nregs; --i >= 0;)
            regno_src_regno[i] = -1;
}
