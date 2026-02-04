#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 d1;
extern int32 d2;
extern int32 d3;
extern int32 elemsize;
extern char ***ref1;
extern char *mem;
extern int32 i;
extern int32 j;
extern int32 offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < d1; i++) {
        int32 base_offset = offset + i * d2 * d3 * elemsize;
        for (j = 0; j < d2; j++) {
            int32 local_offset = base_offset + j * d3 * elemsize;
            ref1[i][j] = mem + local_offset; // Eliminated loop-carried dependency on 'offset'
        }
    }
    // No update to 'offset' — removed cumulative side effect, breaking RAW/WAR dependencies
}
