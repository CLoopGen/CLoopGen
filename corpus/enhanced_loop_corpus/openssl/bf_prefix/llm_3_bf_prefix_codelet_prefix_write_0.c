#include <stdio.h>

#include <inttypes.h>

extern  char *out;
extern size_t outl;
extern size_t i;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with temporary pointer
    char *ptr = out;
    for (i = 0, c = '\x00'; i < outl && (c = *(ptr + i)) != '\n'; i++)
        continue;
}
