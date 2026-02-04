#include <stdio.h>

#include <inttypes.h>

extern int *regno_src_regno;
extern int nregs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *arr = regno_src_regno;
    int j;
    for (j = 0; j < nregs; j++) {
        arr[j] = -1;
    }
    i = nregs;
}
