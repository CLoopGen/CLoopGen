#include <stdio.h>

#include <inttypes.h>

extern int wchar_bytes;
extern char *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 4 (writing every 4th byte, assuming larger context allows it)
    // This variant writes zeros with a fixed stride pattern across the memory region
    int stride = 4;
    char *base = q;
    // Ensure we don't exceed bounds by adjusting effective length
    int effective_bytes = (wchar_bytes + stride - 1) / stride; // Ceiling division
    for (i = 0; i < effective_bytes; i++) {
        base[i * stride] = 0;
    }
    // Update global q to point past the last written element in the original dense sequence
    q += wchar_bytes;
}
