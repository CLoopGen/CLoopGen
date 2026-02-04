#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with step size of 2 (simulating strided pattern)
    // Adjust loop bound to avoid out-of-bounds when striding
    for (i = 0; i < (6 - 1) / 2; i++) {
        q[i * 2] = p[4 - i * 2];  // Write every second element, accessing p and q with stride 2
    }
}
