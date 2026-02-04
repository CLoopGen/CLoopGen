#include <stdio.h>

#include <inttypes.h>

extern int *regno_src_regno;
extern int nregs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = nregs - 1; i >= 0; i -= 3) {
        regno_src_regno[i] = -1;
        if (i - 1 >= 0) regno_src_regno[i - 1] = -1;
        if (i - 2 >= 0) regno_src_regno[i - 2] = -1;
    }
}
