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
    // Variant 2: Strided access with reversed iteration order (still using for-loop) and indirect indexing via temporary array references
    char **xtb = tb->xtb;
    char **mtb = tb->mtb;
    char **itb = tb->itb;
    char **dtb = tb->dtb;
    char *xtb0 = tb->xtb[0];
    char *mtb0 = tb->mtb[0];
    char *itb0 = tb->itb[0];
    char *dtb0 = tb->dtb[0];
    int m_plus_2 = M + 2;

    for (i = rows - 1; i >= 1; i--) {
        xtb[i] = xtb0 + (i * 5);
        mtb[i] = mtb0 + (i * m_plus_2);
        itb[i] = itb0 + (i * m_plus_2);
        dtb[i] = dtb0 + (i * m_plus_2);
    }
}
