#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *s;
extern char *e;
extern char tc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Instead of accessing consecutive elements, we reverse every second element
    int stride = 2;
    int effective_n = n / 2; // Original loop bound
    for (n /= 2; n > 0; n--) {
        char *left = s + (effective_n - n) * stride;
        char *right = e - (effective_n - n) * stride;
        tc = *left;
        *left = *right;
        *right = tc;
    }
}
