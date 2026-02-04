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
    // Variant 2: Strided memory access - update every other element first, then fill gaps (stride=2)
    // This creates a non-unit stride access pattern across the scanptr array
    int i;
    // First pass: even indices
    for (i = 0; i < ncomps; i += 2) {
        ci = i;
        (scanptr + i)->comps_in_scan = 1;
        (scanptr + i)->component_index[0] = ci;
        (scanptr + i)->Ss = Ss;
        (scanptr + i)->Se = Se;
        (scanptr + i)->Ah = Ah;
        (scanptr + i)->Al = Al;
    }
    // Second pass: odd indices
    for (i = 1; i < ncomps; i += 2) {
        ci = i;
        (scanptr + i)->comps_in_scan = 1;
        (scanptr + i)->component_index[0] = ci;
        (scanptr + i)->Ss = Ss;
        (scanptr + i)->Se = Se;
        (scanptr + i)->Ah = Ah;
        (scanptr + i)->Al = Al;
    }
}
