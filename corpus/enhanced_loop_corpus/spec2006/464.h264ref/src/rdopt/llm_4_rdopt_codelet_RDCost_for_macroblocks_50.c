#include <stdio.h>

#include <inttypes.h>

extern int cbp_chroma_block[2][4][4];
extern int i;
extern int j;
extern int k;
extern int cr_cbp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Pointer Array
    // Use an array of pointers to rows to simulate indirect access to the 3D array
    int *ptrs[2*4*4];
    int idx = 0;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 4; j++)
            for (k = 0; k < 4; k++)
                ptrs[idx++] = &cbp_chroma_block[i][j][k];

    // Now iterate through the pointer array and dereference
    for (idx = 0; idx < 2*4*4; idx++)
        if (*(ptrs[idx]))
            cr_cbp = 2;
}
