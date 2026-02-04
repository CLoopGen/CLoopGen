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

jpeg_scan_info *scanptr;
int ncomps;
int ci;

void init_vars() {
    ncomps = 4;
    scanptr = (jpeg_scan_info*)calloc(1, sizeof(jpeg_scan_info));
    scanptr->comps_in_scan = ncomps;
    scanptr->Ss = 0;
    scanptr->Se = 63;
    scanptr->Ah = 0;
    scanptr->Al = 0;
}