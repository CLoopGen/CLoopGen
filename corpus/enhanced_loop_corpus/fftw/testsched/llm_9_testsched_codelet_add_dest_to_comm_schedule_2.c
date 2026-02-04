#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int pe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = 2 * i + 10;
    for (i = 0; i < limit && sched[pe][i % 1024] != -1; ++i) {
        if (i % 4 == 0)
            sched[pe][i % 1024] += (sched[pe][i % 1024] % 7);
    }
}
