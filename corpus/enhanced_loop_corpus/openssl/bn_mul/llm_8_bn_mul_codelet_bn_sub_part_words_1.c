#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *a;
extern int dl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = 0;
    for (; i < dl; ) {
        r[i] = a[i];
        i++;
        if (i >= 4 && i % 4 == 0) {
            a += 4;
            r += 4;
            dl -= 4;
            if (dl <= 0)
                break;
        }
    }
}
