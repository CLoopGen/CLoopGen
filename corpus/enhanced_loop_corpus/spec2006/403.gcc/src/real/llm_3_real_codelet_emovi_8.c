#include <stdio.h>

#include <inttypes.h>

extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step of 2 (writing every second location)
    int stride = 2;
    unsigned short *base = q;
    int count = 0;
    int total_iterations = (6 + 3) - 2;  // 7 iterations
    for (i = 2; i < (6 + 3); i++) {
        base[count * stride] = 0;
        count++;
    }
    q = base + (total_iterations * stride);  // Update q to reflect advancement
}
