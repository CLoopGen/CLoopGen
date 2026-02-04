#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nc; i += 2) {
        if (i + 1 < nc) {
            nmem[i]     = 0;
            nmem[i + 1] = 0;
        } else {
            nmem[i] = 0;
        }
    }
}
