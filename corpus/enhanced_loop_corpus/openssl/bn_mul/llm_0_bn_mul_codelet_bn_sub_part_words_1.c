#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *a;
extern int dl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < dl; i += 4) {
        r[0] = a[0];
        if (i + 1 >= dl) break;
        r[1] = a[1];
        if (i + 2 >= dl) break;
        r[2] = a[2];
        if (i + 3 >= dl) break;
        r[3] = a[3];
        a += 4;
        r += 4;
    }
}
