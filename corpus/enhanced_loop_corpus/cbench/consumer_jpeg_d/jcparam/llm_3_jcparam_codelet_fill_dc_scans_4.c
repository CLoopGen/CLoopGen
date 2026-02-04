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
    // Variant 2: Indirect memory access via index mapping array
    int index_map[4] = {3, 1, 0, 2}; // Arbitrary permutation for indirect access
    for (ci = 0; ci < ncomps; ci++) {
        if (ci < 4) {
            scanptr->component_index[index_map[ci]] = ci;
        }
    }
}
