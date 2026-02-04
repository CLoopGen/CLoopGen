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
    int prev_ii = -1;
    for (k = 0; k < queue_end; k++) {
        ii = queue[k];
        if (prev_ii != -1 && influence[prev_ii] > working[ii]) {
            influence[prev_ii] += influence[ii];
        }
        if (working[ii] > (((int)((0.02) * (1 << 12)) + 0.5)) || influence[ii] == 0)
            influence[ii] += working[ii];
        working[ii] = 0;
        prev_ii = ii;
    }
}
