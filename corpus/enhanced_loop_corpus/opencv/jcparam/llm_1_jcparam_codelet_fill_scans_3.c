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
if (ncomps > 0) {
    for (ci = 0; ci < ncomps; ci += 2) {
        int limit = (ci + 1 < ncomps) ? 2 : 1;
        for (int unroll = 0; unroll < limit; unroll++) {
            scanptr->comps_in_scan = 1;
            scanptr->component_index[0] = ci + unroll;
            scanptr->Ss = Ss;
            scanptr->Se = Se;
            scanptr->Ah = Ah;
            scanptr->Al = Al;
            scanptr++;
        }
    }
}
}
