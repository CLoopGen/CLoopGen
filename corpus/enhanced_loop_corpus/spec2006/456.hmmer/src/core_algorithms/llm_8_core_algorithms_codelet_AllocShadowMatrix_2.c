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
for (i = 1; i < rows; i += 2) {
    if (i + 1 < rows) {
        tb->xtb[i] = tb->xtb[0] + (i * 5);
        tb->mtb[i] = tb->mtb[0] + (i * (M + 2));
        tb->itb[i] = tb->itb[0] + (i * (M + 2));
        tb->dtb[i] = tb->dtb[0] + (i * (M + 2));

        tb->xtb[i+1] = tb->xtb[0] + ((i+1) * 5);
        tb->mtb[i+1] = tb->mtb[0] + ((i+1) * (M + 2));
        tb->itb[i+1] = tb->itb[0] + ((i+1) * (M + 2));
        tb->dtb[i+1] = tb->dtb[0] + ((i+1) * (M + 2));
    } else {
        tb->xtb[i] = tb->xtb[0] + (i * 5);
        tb->mtb[i] = tb->mtb[0] + (i * (M + 2));
        tb->itb[i] = tb->itb[0] + (i * (M + 2));
        tb->dtb[i] = tb->dtb[0] + (i * (M + 2));
    }
}
}
