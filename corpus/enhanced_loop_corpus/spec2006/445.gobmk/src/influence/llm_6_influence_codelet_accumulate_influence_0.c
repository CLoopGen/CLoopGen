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
    int temp_influence[400];
    for (int i = 0; i < 400; i++) {
        temp_influence[i] = influence[i];
    }
    for (k = 0; k < queue_end; k++) {
        ii = queue[k];
        if (working[ii] > (((int)((0.02) * (1 << 12)) + 0.5)) || temp_influence[ii] == 0)
            temp_influence[ii] += working[ii];
        working[ii] = 0;
    }
    for (k = 0; k < queue_end; k++) {
        ii = queue[k];
        influence[ii] = temp_influence[ii];
    }
}
