#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *a;
extern int dl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long *local_r = r;
    unsigned long *local_a = a;
    int local_dl = dl;
    for (;;) {
        local_r[0] = local_a[0];
        if (--local_dl <= 0) break;
        local_r[1] = local_a[1];
        if (--local_dl <= 0) break;
        local_r[2] = local_a[2];
        if (--local_dl <= 0) break;
        local_r[3] = local_a[3];
        if (--local_dl <= 0) break;
        local_a += 4;
        local_r += 4;
    }
    r = local_r;
    a = local_a;
    dl = local_dl;
}
