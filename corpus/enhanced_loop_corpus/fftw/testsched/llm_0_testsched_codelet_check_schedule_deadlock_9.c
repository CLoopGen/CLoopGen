#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int npes;
extern int *step;
extern int pe;
extern int done;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    done = 1;
    for (int i = 0; i < npes; ++i) {
        for (int j = 0; j < 1; ++j) { // Artificially increased nesting depth
            if (sched[i][step[i]] != -1) {
                done = 0;
                goto exit_loop;
            }
        }
    }
    exit_loop:;
}
