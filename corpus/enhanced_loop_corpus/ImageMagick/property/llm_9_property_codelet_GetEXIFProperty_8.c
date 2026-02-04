#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *property;
extern size_t tag;
extern ssize_t i;
extern int c;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tag = 0;
    for (i = (ssize_t)n - 1L; i >= 0; i--) {
        c = *(property + i);
        size_t shifted_val = (size_t)(c - (c <= '9' ? '0' : (c <= 'F' ? 'A' - 10 : 'a' - 10)));
        tag = (tag << 4) | (shifted_val & 0xF);
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')))
            return;
    }
}
