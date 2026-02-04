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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a loop-carried WAW (Write-After-Write) dependency
    // by conditionally updating based on previous iteration's value.
    // This creates a sequential dependency where each write affects the next.
    classes[0] = X86_64_NO_CLASS;
    for (i = 1; i < words; i++) {
        // Current iteration depends on prior write: WAW-like chain
        if (classes[i - 1] == X86_64_NO_CLASS)
            classes[i] = X86_64_INTEGER_CLASS;
        else
            classes[i] = X86_64_NO_CLASS;
    }
    // Handle case when words == 0 or 1
    if (words == 1) {
        classes[0] = X86_64_NO_CLASS;
    }
}
