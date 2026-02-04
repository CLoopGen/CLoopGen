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
    unsigned long *local_ptr = &(a->d[tmp_top]);
    int local_top = tmp_top;
    for (; local_top > 0; local_top--) {
        local_ptr--;
        if (*local_ptr != 0) {
            ftl = local_ptr;
            break;
        }
    }
    ftl = local_ptr; // Ensure ftl is updated even if no non-zero found
}
