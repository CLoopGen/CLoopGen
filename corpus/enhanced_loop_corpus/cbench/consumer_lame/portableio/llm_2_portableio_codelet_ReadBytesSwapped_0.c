#include <stdio.h>

#include <inttypes.h>

extern char *p;
extern int n;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (accessing every second element)
    // This variant reverses elements at even strides from both ends toward the center
    char temp;
    int stride = 2;
    char *left = p;
    char *right = q - 1; // q starts one before the original end

    for (; left < right; left += stride, right -= stride) {
        if (left + 1 <= right) {
            n = *(left + 1);
            *(left + 1) = *(right - 1);
            *(right - 1) = n;
        }
    }
}
