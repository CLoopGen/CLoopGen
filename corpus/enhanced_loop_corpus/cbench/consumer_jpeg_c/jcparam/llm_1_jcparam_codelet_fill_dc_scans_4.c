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
int temp_ci = 0;
for (ci = 0; ci < ncomps; ci++) {
    scanptr->component_index[ci] = temp_ci;
    temp_ci++;
}
}
