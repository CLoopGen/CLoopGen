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
    for (int j = 0; j < 1; j++) {
        for (i = 1; i < rows; i++) {
            tb->xtb[i] = tb->xtb[0] + (i * 5);
            tb->mtb[i] = tb->mtb[0] + (i * (M + 2));
            tb->itb[i] = tb->itb[0] + (i * (M + 2));
            tb->dtb[i] = tb->dtb[0] + (i * (M + 2));
        }
    }
}
