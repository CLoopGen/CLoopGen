#include <stdio.h>

#include <inttypes.h>

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
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW dependency by reordering write operations
    // and introducing a temporary array to create artificial write-after-write hazard
    int temp_index[4];
    for (ci = 0; ci < ncomps; ci++) {
        temp_index[ci] = ci;
    }
    // Artificially create WAW by writing twice with dependency on previous iteration
    for (ci = 0; ci < ncomps; ci++) {
        if (ci > 0) {
            scanptr->component_index[ci] = temp_index[ci] + scanptr->component_index[ci-1]; // WAW and RAW dependency
        } else {
            scanptr->component_index[ci] = temp_index[ci];
        }
    }
}
