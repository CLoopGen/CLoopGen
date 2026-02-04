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
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[4];
    for (ci = 0; ci < ncomps; ci++)
        temp[ci] = ci;
    for (ci = 0; ci < ncomps; ci++)
        scanptr->component_index[ci] = temp[ci];
}
