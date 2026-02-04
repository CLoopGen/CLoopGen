#include <stdio.h>

#include <inttypes.h>

extern int *kassign;
extern char *tassign;
extern int s1;
extern int s2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse)
    for (; s2 >= s1; s2 -= 2) {
        kassign[s2] = 1;
        tassign[s2] = 5;
        if (s2 == s1) break;  // Prevent underflow when step size skips s1
    }
}
