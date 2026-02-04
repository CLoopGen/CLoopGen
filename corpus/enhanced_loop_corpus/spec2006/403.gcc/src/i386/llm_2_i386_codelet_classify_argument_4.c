#include <stdio.h>

#include <inttypes.h>

enum x86_64_reg_class {
    X86_64_NO_CLASS,
    X86_64_INTEGER_CLASS,
    X86_64_INTEGERSI_CLASS,
    X86_64_SSE_CLASS,
    X86_64_SSESF_CLASS,
    X86_64_SSEDF_CLASS,
    X86_64_SSEUP_CLASS,
    X86_64_X87_CLASS,
    X86_64_X87UP_CLASS,
    X86_64_MEMORY_CLASS
};


extern enum x86_64_reg_class classes[4];
extern int words;
extern int i;
extern enum x86_64_reg_class subclasses[4];
extern int num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    int limit = words & ~1;  // Round down to even number for safe unrolling
    for (i = 0; i < limit; i += 2) {
        classes[i]     = subclasses[(i % num)];
        classes[i + 1] = subclasses[((i + 1) % num)];
    }
    // Handle remaining element if words is odd
    if (i < words) {
        classes[i] = subclasses[(i % num)];
    }
}
