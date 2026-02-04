#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int factor = 3;
    for (i = 0; i < nc; i++) {
        nmem[i] = i * factor + 1;
        nmem[i] -= i * factor;
    }
}
