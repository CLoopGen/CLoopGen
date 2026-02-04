#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int pe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; sched[pe][i] != -1 && i < 1000; ++i) {
        if (sched[pe][i] == 0) {
            break;
        }
    }
}
