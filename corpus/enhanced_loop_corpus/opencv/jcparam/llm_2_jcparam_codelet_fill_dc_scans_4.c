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
    // Variant 1: Strided memory access (stride of 2, wrapping around using modulo)
    // This modifies the access pattern to write every second element in a circular manner
    for (ci = 0; ci < ncomps; ci++) {
        int index = (ci * 2) % 4;  // Strided access with wrap-around for fixed-size array
        scanptr->component_index[index] = ci;
    }
}
