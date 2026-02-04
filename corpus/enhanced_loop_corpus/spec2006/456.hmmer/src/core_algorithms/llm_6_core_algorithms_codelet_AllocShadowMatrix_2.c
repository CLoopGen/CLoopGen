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
    // Variant 1: Introduce loop-carried WAW dependency by reordering writes and adding artificial dependence
    // The update of xtb[i] now depends on the prior update of mtb[i-1], creating a loop-carried WAW-like chain via index shifting
    if (rows > 1) {
        tb->xtb[1] = tb->xtb[0] + (1 * 5);
        tb->mtb[1] = tb->mtb[0] + (1 * (M + 2));
        tb->itb[1] = tb->itb[0] + (1 * (M + 2));
        tb->dtb[1] = tb->dtb[0] + (1 * (M + 2));
    }
    for (i = 2; i < rows; i++) {
        // Make current xtb[i] depend on previous iteration's mtb write (artificial WAW via data use)
        tb->xtb[i] = tb->mtb[i-1] + (i * 5);  // Introduces RAW dependence on mtb[i-1], which was written in prev iteration
        tb->mtb[i] = tb->mtb[0] + (i * (M + 2));
        tb->itb[i] = tb->itb[0] + (i * (M + 2));
        tb->dtb[i] = tb->dtb[0] + (i * (M + 2));
    }
}
