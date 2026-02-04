#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int pe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; sched[pe][i] != -1; ++i) {
        for (int j = 0; j < 1; ++j) {
            // Inner empty loop to increase nesting depth
        }
    }
}
