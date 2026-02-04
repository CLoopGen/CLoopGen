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

enum x86_64_reg_class classes[4];
int words;
int i;
enum x86_64_reg_class subclasses[4];
int num;

void init_vars() {
    words = 4;
    num = 4;
    for (int j = 0; j < 4; j++) {
        subclasses[j] = (enum x86_64_reg_class)(j % 8);
    }
}