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
extern int Ss;
extern int Se;
extern int Ah;
extern int Al;
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Strided access: process every 2nd element forward, then handle remainder
int stride = 2;
for (ci = 0; ci < ncomps; ci += stride) {
    int next = ci + 1;
    scanptr[ci].comps_in_scan = 1;
    scanptr[ci].component_index[0] = ci;
    scanptr[ci].Ss = Ss;
    scanptr[ci].Se = Se;
    scanptr[ci].Ah = Ah;
    scanptr[ci].Al = Al;

    if (next < ncomps) {
        scanptr[next].comps_in_scan = 1;
        scanptr[next].component_index[0] = next;
        scanptr[next].Ss = Ss;
        scanptr[next].Se = Se;
        scanptr[next].Ah = Ah;
        scanptr[next].Al = Al;
    }
}
}
