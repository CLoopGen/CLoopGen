#include <stdio.h>

#include <inttypes.h>

extern int k1;
extern int k3;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int cur;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using pointer arithmetic to flatten indexing
    int *mm_ptr = mmx[cur] + k1;
    int *im_ptr = imx[cur] + k1;
    int *dm_ptr = dmx[cur] + k1;
    int count = k3 - k1 + 1;
    for (k = 0; k < count; k++)
        mm_ptr[k] = im_ptr[k] = dm_ptr[k] = -987654321;
}
