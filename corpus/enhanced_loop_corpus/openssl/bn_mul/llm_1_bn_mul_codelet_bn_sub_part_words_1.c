#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *a;
extern int dl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < (dl + 3) / 4; ++outer) {
        for (int inner = 0; inner < 4 && (outer * 4 + inner) < dl; ++inner) {
            r[inner] = a[inner];
        }
        a += 4;
        r += 4;
    }
}
