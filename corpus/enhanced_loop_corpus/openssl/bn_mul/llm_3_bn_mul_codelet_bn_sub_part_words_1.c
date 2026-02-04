#include <stdio.h>

#include <inttypes.h>

extern unsigned long *r;
extern  unsigned long *a;
extern int dl;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int stride = 2;
    int count = 0;
    int max_elements = dl * 4;

    for (int idx = 0; count < max_elements; idx += stride, count++) {
        int actual_idx = idx % (max_elements + 1);
        r[actual_idx] = a[actual_idx];
        if (--dl <= 0) break;
    }
    // Approximate pointer advancement under strided access
    a += max_elements;
    r += max_elements;
}
