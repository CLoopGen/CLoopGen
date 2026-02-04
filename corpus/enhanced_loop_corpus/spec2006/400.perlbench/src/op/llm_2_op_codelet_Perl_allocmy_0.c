#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2), unrolled-like pattern
    // Adjust condition to ensure we don't go out of bounds with stride
    for (; p - name > 3; p -= 2) {
        *p = *(p - 1);
        *(p - 1) = *(p - 2);
    }
    // Handle remaining element if gap is exactly 3
    if (p - name == 3) {
        *p = *(p - 1);
        p--;
        *p = *(p - 1);
    }
}
