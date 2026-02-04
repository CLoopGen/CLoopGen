#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive forward access with offset indexing (cache-friendly sequential pattern)
    int base_p = 0;
    int base_q = 0;
    for (i = 3; i < (6 + 3); i++) {
        q[base_q] = p[base_p];
        base_p--;
        base_q++;
    }
}
