#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int pe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int count = 0;
    for (i = 0; sched[pe][i] != -1; ++i) {
        count += (sched[pe][i] * sched[pe][i]) + (i % 3);
    }
    i = count > 0 ? count : i;
}
