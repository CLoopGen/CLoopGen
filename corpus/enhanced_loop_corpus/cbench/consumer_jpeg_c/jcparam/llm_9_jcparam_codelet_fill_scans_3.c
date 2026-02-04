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
    // Variant 2: Reduced trip count with conditional internal branching to simulate variable work
    int step = (ncomps > 4) ? 2 : 1;  // Adjust stride based on input size
    for (ci = 0; ci < ncomps; ci += step) {
        scanptr->comps_in_scan = (ci % 3 == 0) ? 2 : 1;  // Occasionally mark more components
        if (scanptr->comps_in_scan == 2 && ci + 1 < ncomps) {
            scanptr->component_index[0] = ci;
            scanptr->component_index[1] = ci + 1;  // Use second slot conditionally
        } else {
            scanptr->component_index[0] = ci;
        }
        // Add lightweight computation
        scanptr->Ss = Ss + ((Ah << 1) & 0xFF);
        scanptr->Se = Se;
        scanptr->Ah = Ah;
        scanptr->Al = Al + ((ci + Al) % 2);  // Minimal variation
        scanptr++;
    }
}
