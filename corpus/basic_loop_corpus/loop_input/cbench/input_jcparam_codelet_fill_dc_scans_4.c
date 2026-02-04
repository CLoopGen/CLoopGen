#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct {
    int comps_in_scan;
    int component_index[4];
    int Ss;
    int Se;
    int Ah;
    int Al;
} jpeg_scan_info;

jpeg_scan_info *scanptr;
int ncomps;
int ci;

void init_vars() {
    ncomps = 4;
    scanptr = (jpeg_scan_info*)malloc(sizeof(jpeg_scan_info));
    if (scanptr == NULL) {
        // Handle allocation failure, though not allowed to print per instructions
        // Just ensure valid state; in practice this would be fatal
        ncomps = 0;
        return;
    }
    scanptr->comps_in_scan = 0;
    scanptr->Ss = 0;
    scanptr->Se = 0;
    scanptr->Ah = 0;
    scanptr->Al = 0;
}