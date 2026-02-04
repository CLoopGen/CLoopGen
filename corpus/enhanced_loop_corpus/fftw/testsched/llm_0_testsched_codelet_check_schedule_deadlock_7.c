#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int *step;
extern int pe;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < npes; ++i)
    for (pe = 0; pe < npes; ++pe)
        step[pe] = 0;
}
