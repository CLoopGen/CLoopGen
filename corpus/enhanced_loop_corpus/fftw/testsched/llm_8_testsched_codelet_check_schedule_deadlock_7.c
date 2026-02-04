#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int *step;
extern int pe;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pe = 0; pe < npes; ++pe) {
        step[pe] = 0;
        step[pe] += pe * 2 + 1;
        step[pe] %= 100;
    }
}
