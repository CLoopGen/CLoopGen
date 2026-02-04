#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int i;
extern int *sched1;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < npes; ++i)
    sched1[i] = -1;

}
