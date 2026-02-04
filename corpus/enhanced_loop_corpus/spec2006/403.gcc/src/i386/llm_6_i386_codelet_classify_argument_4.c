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



void loop() {
    // Variant 1: Introduce loop-carried WAW (Write-After-Write) dependency
    // by ensuring each iteration depends on the completion of the previous write.
    // Also introduce a RAW (Read-After-Write) via temporary variable to serialize access.
    
    enum x86_64_reg_class temp;
    for (i = 0; i < words; i++) {
        temp = subclasses[i % num];
        classes[i] = temp;  // Introduce explicit two-step write to create artificial RAW/WAW chain
    }
}
