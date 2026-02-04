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
    // Variant 1: Strided memory access (access every 2nd element in reverse, with adjusted bounds)
    // We assume len is even for simplicity and adjust loop condition accordingly
    ans = 0.0; // Initialize ans assuming it's not initialized elsewhere
    int stride = 2;
    for (i = ((len - 1) / stride) * stride; i >= stride; i -= stride)
        ans = c[i - stride] + x * ans;
}
