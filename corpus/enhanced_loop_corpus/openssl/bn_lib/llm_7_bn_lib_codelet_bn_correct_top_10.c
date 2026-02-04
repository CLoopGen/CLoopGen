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



void loop(){
    unsigned long *temp_ftl = &(a->d[tmp_top]);
    int i;
    // Introduce a WAW dependency by decoupling ftl update from loop iteration
    for (i = tmp_top; i > 0; i--) {
        temp_ftl--;
        if (*temp_ftl != 0) {
            break;
        }
    }
    // Final write to shared ftl after loop (WAW: write-after-write with original ftl)
    ftl = temp_ftl;
    // Eliminate loop-carried data dependency on ftl, only use it post-loop
}
