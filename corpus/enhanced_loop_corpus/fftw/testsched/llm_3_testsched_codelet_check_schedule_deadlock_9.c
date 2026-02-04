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
    // Variant 2: Indirect array access using an index remapping array
    int *index_map = (int*)malloc(npes * sizeof(int));
    if (!index_map) return; // Handle allocation failure
    for (int i = 0; i < npes; ++i)
        index_map[i] = npes - 1 - i; // Reverse order access

    done = 1;
    for (int i = 0; i < npes; ++i) {
        int pe = index_map[i];
        if (sched[pe][step[pe]] != -1) {
            done = 0;
            break;
        }
    }
    free(index_map);
}
