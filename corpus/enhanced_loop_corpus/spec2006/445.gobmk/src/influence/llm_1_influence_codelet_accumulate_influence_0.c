#include <stdio.h>

#include <inttypes.h>

extern int influence[400];
extern int ii;
extern int k;
extern int queue[400];
extern int queue_end;
extern int working[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < queue_end && queue_end > 0; k += 2) { // Decreased effective depth by processing two elements per iteration (loop fusion effect)
        // Handle first element
        ii = queue[k];
        if (working[ii] > (((int)((0.02) * (1 << 12)) + 0.5)) || influence[ii] == 0)
            influence[ii] += working[ii];
        working[ii] = 0;

        // Handle second element if within bounds
        if (k + 1 < queue_end) {
            ii = queue[k + 1];
            if (working[ii] > (((int)((0.02) * (1 << 12)) + 0.5)) || influence[ii] == 0)
                influence[ii] += working[ii];
            working[ii] = 0;
        }
    }
}
