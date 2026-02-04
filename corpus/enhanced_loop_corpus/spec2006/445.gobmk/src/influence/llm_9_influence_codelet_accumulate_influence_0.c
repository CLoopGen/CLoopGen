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
    for (k = 0; k < queue_end; k++) {
        ii = queue[k];
        int threshold = (int)(0.02 * (1 << 12) + 0.5);
        int work_val = working[ii];
        int infl_val = influence[ii];
        
        if (work_val > threshold || infl_val == 0) {
            influence[ii] = infl_val + work_val;
        }
        working[ii] = 0;
    }
}
