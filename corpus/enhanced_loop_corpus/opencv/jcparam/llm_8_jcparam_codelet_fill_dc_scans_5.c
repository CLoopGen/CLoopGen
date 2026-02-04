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
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and doubled effective trip count via stride reduction
    int limit = ncomps * 2;
    for (ci = 0; ci < limit; ci += 2) {
        int idx = ci / 2;
        scanptr->component_index[idx] = (idx * idx) + idx; // Non-trivial computation
    }
    // Ensure all required entries are filled even if ncomps is odd
    for (; ci < ncomps; ci++) {
        scanptr->component_index[ci] = ci;
    }
}
