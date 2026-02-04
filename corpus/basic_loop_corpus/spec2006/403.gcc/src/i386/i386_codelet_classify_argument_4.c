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
for (i = 0; i < words; i++)
    classes[i] = subclasses[i % num];

}
