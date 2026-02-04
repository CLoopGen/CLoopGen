#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int comps_in_scan;
    int component_index[4];
    int Ss;
    int Se;
    int Ah;
    int Al;
} jpeg_scan_info;

extern jpeg_scan_info *scanptr;
extern int ncomps;
extern int Ss;
extern int Se;
extern int Ah;
extern int Al;
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce loop-carried dependence via artificial sequential update of a field
    // Simulates a cumulative effect across iterations using a derived value from previous write
    int prev_ci = -1;
    for (ci = 0; ci < ncomps; ci++) {
        scanptr->comps_in_scan = 1;
        scanptr->component_index[0] = ci;
        scanptr->Ss = Ss;
        scanptr->Se = Se;
        scanptr->Ah = Ah;
        // Create a RAW and WAW dependency: Al depends on the previous iteration's ci through prev_ci
        scanptr->Al = (prev_ci == -1) ? Al : Al + (ci - prev_ci);
        prev_ci = ci;  // Carry dependency to next iteration
        scanptr++;
    }
}
