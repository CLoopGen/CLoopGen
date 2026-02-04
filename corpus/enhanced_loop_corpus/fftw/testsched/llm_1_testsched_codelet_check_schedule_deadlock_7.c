#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int *step;
extern int pe;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (npes > 0) {
    for (pe = 0; pe < npes; ++pe) {
        step[pe] = 0;
        for (int inner = 1; inner < 2; ++inner) {
            // Artificially deepened loop nest with trivial inner loop
        }
    }
}
}
