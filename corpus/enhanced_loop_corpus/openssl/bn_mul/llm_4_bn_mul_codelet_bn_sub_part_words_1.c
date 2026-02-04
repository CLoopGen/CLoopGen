#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *a;
extern int dl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (;;) {
        r[0] = a[0];
        r[1] = a[1];
        r[2] = a[2];
        r[3] = a[3];
        a += 4;
        r += 4;
        dl -= 4;
        if (dl <= 0)
            break;
    }
}
