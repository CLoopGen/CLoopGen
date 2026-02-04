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
int step = 2, limit = (ncomps + 1) / 2;
for (ci = 0; ci < limit; ci += 1) {
    int mapped_ci = ci * step;
    scanptr->comps_in_scan = 1;
    scanptr->component_index[0] = mapped_ci;
    scanptr->Ss = Ss;
    scanptr->Se = Se;
    scanptr->Ah = Ah;
    scanptr->Al = Al;
    scanptr++;

    if (mapped_ci + 1 < ncomps) {
        scanptr->comps_in_scan = 1;
        scanptr->component_index[0] = mapped_ci + 1;
        scanptr->Ss = Ss;
        scanptr->Se = Se;
        scanptr->Ah = Ah;
        scanptr->Al = Al;
        scanptr++;
    }
}
}
