#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int **sched;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *temp[npes];
    for (i = 0; i < npes; ++i) {
        temp[i] = ((void *)0);
        sched[i] = temp[i]; // Introduces temporary storage, creating a WAW-free pattern with local RAW dependency
    }
}
