#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern  int len;
extern  double x;
extern int i;
extern double ans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse, adjusting logic accordingly)
    // Assume len is even for simplicity, and we process elements with stride 2
    ans = 0.0; // Initialize ans as this changes accumulation behavior
    for (i = len - 1; i > 0; i -= 2) {
        int idx = i - 1;
        if (idx >= 0) {
            ans = c[idx] + x * ans;
        }
    }
}
