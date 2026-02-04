#include <stdio.h>

#include <inttypes.h>

extern int *regno_src_regno;
extern int nregs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = nregs; --i >= 0;) {
        temp = regno_src_regno[i];
        regno_src_regno[i] = temp - 1;
    }
}
