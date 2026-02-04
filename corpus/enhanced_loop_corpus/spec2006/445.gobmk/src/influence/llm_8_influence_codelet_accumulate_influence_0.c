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
    for (k = 0; k < queue_end && k < 200; k += 2) {
        ii = queue[k];
        if (working[ii] > (((int)((0.02) * (1 << 12)) + 0.5)) || influence[ii] == 0)
            influence[ii] += working[ii];
        working[ii] = 0;
        
        if (k + 1 < queue_end) {
            int jj = queue[k + 1];
            if (working[jj] > (((int)((0.02) * (1 << 12)) + 0.5)) || influence[jj] == 0)
                influence[jj] += working[jj];
            working[jj] = 0;
        }
    }
}
