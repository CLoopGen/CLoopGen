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
for (ci = 0; ci < ncomps; ci++) {
    int idx = ci * 1; // Strided access pattern with stride 1 (can be extended)
    (scanptr + idx)->comps_in_scan = 1;
    (scanptr + idx)->component_index[0] = ci;
    (scanptr + idx)->Ss = Ss;
    (scanptr + idx)->Se = Se;
    (scanptr + idx)->Ah = Ah;
    (scanptr + idx)->Al = Al;
}
}
