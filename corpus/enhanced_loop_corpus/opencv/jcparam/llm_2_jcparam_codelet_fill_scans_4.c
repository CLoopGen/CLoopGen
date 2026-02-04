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
    jpeg_scan_info *base_scanptr = scanptr;
    for (ci = 0; ci < ncomps; ci++) {
        jpeg_scan_info *current = base_scanptr + ci;
        current->comps_in_scan = 1;
        current->component_index[0] = ci;
        current->Ss = Ss;
        current->Se = Se;
        current->Ah = Ah;
        current->Al = Al;
    }
}
