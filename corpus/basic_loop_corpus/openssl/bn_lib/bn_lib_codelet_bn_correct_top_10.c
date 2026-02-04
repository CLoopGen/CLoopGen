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
for (ftl = &(a->d[tmp_top]); tmp_top > 0; tmp_top--) {
    ftl--;
    if (*ftl != 0)
        break;
}

}
