#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int **sched;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices[1024]; // Assume max npes is 1024
    int j;
    for (j = 0; j < npes; ++j)
        indices[j] = &j;

    for (j = 0; j < npes; ++j)
        sched[*indices[j]] = ((void *)0);
}
