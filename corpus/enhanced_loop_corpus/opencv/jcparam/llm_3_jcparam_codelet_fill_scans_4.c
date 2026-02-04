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
    int ci;
    // Strided access: process every second element forward, then fill in the gaps
    // Assumes ncomps is at least 1 and behavior is adjusted for strided memory writes
    jpeg_scan_info *temp_ptr = scanptr;

    // First pass: even indices
    for (ci = 0; ci < ncomps; ci += 2) {
        temp_ptr->comps_in_scan = 1;
        temp_ptr->component_index[0] = ci;
        temp_ptr->Ss = Ss;
        temp_ptr->Se = Se;
        temp_ptr->Ah = Ah;
        temp_ptr->Al = Al;
        temp_ptr += 2;
    }

    temp_ptr = scanptr + 1;
    // Second pass: odd indices
    for (ci = 1; ci < ncomps; ci += 2) {
        temp_ptr->comps_in_scan = 1;
        temp_ptr->component_index[0] = ci;
        temp_ptr->Ss = Ss;
        temp_ptr->Se = Se;
        temp_ptr->Ah = Ah;
        temp_ptr->Al = Al;
        temp_ptr += 2;
    }
}
