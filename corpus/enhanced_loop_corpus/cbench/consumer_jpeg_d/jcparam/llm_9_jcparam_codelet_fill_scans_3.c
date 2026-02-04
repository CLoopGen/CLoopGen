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
    // Variant 2: Reduced arithmetic and simplified access with conditional skip pattern
    // Simulates sparse update by skipping every other component, reducing effective work
    scanptr->Ss = Ss;
    scanptr->Se = Se;
    scanptr->Ah = Ah;
    scanptr->Al = Al;

    for (ci = 0; ci < ncomps; ci += 2) {  // Process only even indices
        scanptr->comps_in_scan = 1;
        scanptr->component_index[0] = ci;

        // Batch-constant fields are pre-set outside the loop logic
        scanptr++;
        
        // Add lightweight dependency to increase data flow without heavy math
        if (ci > 0 && (ci % 4 == 0)) {
            (scanptr - 1)->Al += 1;  // Minor post-adjustment based on position
        }
    }

    // Final cleanup pass for odd ncomps to maintain correctness
    if (ncomps % 2 == 1) {
        ci = ncomps - 1;
        scanptr->comps_in_scan = 1;
        scanptr->component_index[0] = ci;
        scanptr->Ss = Ss;
        scanptr->Se = Se;
        scanptr->Ah = Ah;
        scanptr->Al = Al;
    }
}
