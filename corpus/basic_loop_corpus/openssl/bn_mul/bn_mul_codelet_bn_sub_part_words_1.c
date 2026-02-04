#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *a;
extern int dl;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (;;) {
    r[0] = a[0];
    if (--dl <= 0)
        break;
    r[1] = a[1];
    if (--dl <= 0)
        break;
    r[2] = a[2];
    if (--dl <= 0)
        break;
    r[3] = a[3];
    if (--dl <= 0)
        break;
    a += 4;
    r += 4;
}

}
