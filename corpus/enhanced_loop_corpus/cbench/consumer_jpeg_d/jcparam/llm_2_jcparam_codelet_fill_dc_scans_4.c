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
    // Variant 1: Strided memory access (stride of 2, with bounds check)
    int idx = 0;
    for (ci = 0; ci < ncomps; ci++) {
        idx = ci * 2;
        if (idx < 4) {  // Ensure within bounds of component_index[4]
            scanptr->component_index[idx] = ci;
        }
    }
}
