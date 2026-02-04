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
    // Variant 2: Indirect memory access using an index mapping (simulates irregular access pattern)
    int indices[4] = {0, 1, 2, 3}; // Assume ncomps <= 4 as per struct definition
    for (ci = 0; ci < ncomps; ci++)
        scanptr->component_index[indices[ci]] = ci;
}
