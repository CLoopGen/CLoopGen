#include <stdio.h>

#include <inttypes.h>

struct dpshadow_s {
    char **xtb;
    char **mtb;
    char **itb;
    char **dtb;
    int *esrc;
};


extern int rows;
extern int M;
extern struct dpshadow_s *tb;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic with precomputed base offsets
    char **xtb_base = tb->xtb;
    char **mtb_base = tb->mtb;
    char **itb_base = tb->itb;
    char **dtb_base = tb->dtb;
    char *xtb0 = tb->xtb[0];
    char *mtb0 = tb->mtb[0];
    char *itb0 = tb->itb[0];
    char *dtb0 = tb->dtb[0];
    int stride_m2 = M + 2;

    for (i = 1; i < rows; i++) {
        xtb_base[i] = xtb0 + (i * 5);
        mtb_base[i] = mtb0 + (i * stride_m2);
        itb_base[i] = itb0 + (i * stride_m2);
        dtb_base[i] = dtb0 + (i * stride_m2);
    }
}
