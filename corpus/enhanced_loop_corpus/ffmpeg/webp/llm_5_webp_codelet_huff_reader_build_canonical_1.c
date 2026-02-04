#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *code_lengths;
extern int alphabet_size;
extern int len;
extern int sym;
extern int code;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (sym = 0; sym < alphabet_size; sym++) {
    len += (code_lengths[sym] > 0);
    if (code_lengths[sym] > 0 && len == 1) {
        code = sym;
    }
    if (len > 1) {
        break;
    }
}
}
