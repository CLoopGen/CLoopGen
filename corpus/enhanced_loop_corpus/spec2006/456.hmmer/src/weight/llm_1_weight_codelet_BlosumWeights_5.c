#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nc; i += 2) {
        nmem[i] = 0;
        if (i + 1 < nc)
            nmem[i + 1] = 0;
    }
}
