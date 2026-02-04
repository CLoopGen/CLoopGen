#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int *step;
extern int pe;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < npes; ++i)
        step[i] = step[i] + 1 - 1; // Introduce a RAW dependency: read before write (though semantically same)
}
