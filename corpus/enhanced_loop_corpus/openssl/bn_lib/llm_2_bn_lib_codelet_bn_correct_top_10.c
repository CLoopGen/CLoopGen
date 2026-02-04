#include <stdio.h>

#include <inttypes.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};


typedef struct bignum_st BIGNUM;

extern BIGNUM *a;
extern unsigned long *ftl;
extern int tmp_top;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2)
    for (ftl = &(a->d[tmp_top]); tmp_top > 0; tmp_top -= 2) {
        ftl -= 2;
        if (tmp_top >= 2 && *(ftl + 1) != 0) {
            ftl = ftl + 1;
            break;
        }
        if (*ftl != 0)
            break;
        if (tmp_top == 1) {
            ftl--;
            if (*ftl != 0)
                break;
        }
    }
}
