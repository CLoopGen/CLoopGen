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

enum x86_64_reg_class classes[65536];
int words;
int i;

void init_vars() {
    words = 65536;
    for (int j = 0; j < words; j++) {
        classes[j] = X86_64_MEMORY_CLASS;
    }
}