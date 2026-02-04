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
    int temp_Ss = Ss;
    int temp_Se = Se;
    int temp_Ah = Ah;
    int temp_Al = Al;
    for (ci = 0; ci < ncomps; ci++) {
        scanptr->comps_in_scan = 1;
        scanptr->component_index[0] = ci;
        // Introduce temporary variables to remove direct dependence on global vars in each iteration
        // This reduces potential WAW/WAR hazards if globals were modified elsewhere, and creates a local data dependency
        scanptr->Ss = temp_Ss;
        scanptr->Se = temp_Se;
        scanptr->Ah = temp_Ah;
        scanptr->Al = temp_Al;
        scanptr++;
    }
}
