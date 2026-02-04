#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern ptrdiff_t pitch;
extern int i;
extern  int32_t *src;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Consecutive memory access using local array to promote spatial locality
int32_t local_src[16];
int16_t local_out[4];

for (i = 0; i < 4; i++) {
    // Prefetch consecutive block of src into local buffer (simulating cache-friendly access)
    for (int j = 0; j < 4; j++) {
        local_src[j] = src[i * 4 + j]; // Flatten 2D-like access into linear consecutive reads
    }

    if (!local_src[0] && !local_src[1] && !local_src[2] && !local_src[3]) {
        local_out[0] = local_out[1] = local_out[2] = local_out[3] = 0;
    } else {
        t0 = (local_src[0]) - (local_src[2]);
        t1 = (local_src[0]) + (local_src[2]);
        t2 = (t0);
        ;
        t0 = (((local_src[1]) + (local_src[3]) * 2 + 2) >> 2) + (local_src[1]);
        t3 = (((local_src[1]) * 2 - (local_src[3]) + 2) >> 2) - (local_src[3]);
        t4 = (t0);
        ;
        t0 = (t1) - (t4);
        t1 = (t1) + (t4);
        t4 = (t0);
        ;
        t0 = (t2) - (t3);
        t2 = (t2) + (t3);
        t3 = (t0);
        ;
        local_out[0] = (((t1) + 1) >> 1);
        local_out[1] = (((t2) + 1) >> 1);
        local_out[2] = (((t3) + 1) >> 1);
        local_out[3] = (((t4) + 1) >> 1);
    }

    // Write back results consecutively to output with pitch stride
    for (int j = 0; j < 4; j++) {
        ((int16_t*)((char*)out + i * pitch))[j] = local_out[j];
    }
}
}
