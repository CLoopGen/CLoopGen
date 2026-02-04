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
    // Introduce loop-carried RAW dependency: each iteration depends on previous write via scanptr
    // Also introduce artificial sequential dependency using cumulative index

    int offset = 0;
    for (ci = 0; ci < ncomps; ci++) {
        // Create artificial dependency: current write depends on prior scanptr state
        if (ci > 0) {
            // Read from previous element (RAW dependence across iterations)
            offset += (scanptr - 1)->comps_in_scan;
        }

        scanptr->comps_in_scan = 1 + offset;  // WAW and RAW carried through loop
        scanptr->component_index[0] = ci + offset;
        scanptr->Ss = Ss;
        scanptr->Se = Se;
        scanptr->Ah = Ah;
        scanptr->Al = Al;

        // Force scanptr advance to create inter-iteration pointer dependency
        scanptr++;
    }
}
