#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *a;
extern int dl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp0, temp1, temp2, temp3;
    for (;;) {
        temp0 = a[0];
        temp1 = a[1];
        temp2 = a[2];
        temp3 = a[3];
        r[0] = temp0;
        if (--dl <= 0) break;
        r[1] = temp1;
        if (--dl <= 0) break;
        r[2] = temp2;
        if (--dl <= 0) break;
        r[3] = temp3;
        if (--dl <= 0) break;
        a += 4;
        r += 4;
    }
}
