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

extern int i;
extern int top;
extern BIGNUM am;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int start = am.top;
    int end = (top > am.dmax) ? am.dmax : top;
    for (i = start; i < end; i += 2) {
        am.d[i] = 0;
        if (i + 1 < end)
            am.d[i + 1] = 0;
    }
    if (i < top && i < am.dmax)
        am.d[i] = 0;
}
