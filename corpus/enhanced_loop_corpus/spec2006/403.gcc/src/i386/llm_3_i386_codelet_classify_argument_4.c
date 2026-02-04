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
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access pattern)
    // Assume indices are precomputed in a global array 'indices', but since we can't modify globals,
    // simulate indirect access via a computed index sequence: reverse order access
    for (i = 0; i < words; i++) {
        int rev_index = words - 1 - i;  // Reverse indexing
        int src_index = rev_index % num;
        classes[rev_index] = subclasses[src_index];
    }
}
