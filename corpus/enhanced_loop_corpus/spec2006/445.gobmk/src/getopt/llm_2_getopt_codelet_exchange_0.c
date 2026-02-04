#include <stdio.h>

#include <inttypes.h>

extern char **argv;
extern int bottom;
extern int middle;
extern int top;
extern char *tem;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements, access every second element in a strided manner.
    // This changes the memory access pattern to non-unit stride, potentially affecting cache behavior.
    int stride = 2;
    int limit = len / stride;
    for (i = 0; i < limit; i++) {
        int idx = i * stride;
        tem = argv[bottom + idx];
        argv[bottom + idx] = argv[top - (middle - bottom) + idx];
        argv[top - (middle - bottom) + idx] = tem;
    }
    // Handle remaining elements if len is not divisible by stride
    for (i = (len / stride) * stride; i < len; i++) {
        tem = argv[bottom + i];
        argv[bottom + i] = argv[top - (middle - bottom) + i];
        argv[top - (middle - bottom) + i] = tem;
    }
}
