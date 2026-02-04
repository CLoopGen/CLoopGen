#include <stdio.h>

#include <inttypes.h>

extern  char *out;
extern size_t outl;
extern size_t i;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char local_c = '\x00';
    size_t local_i;
    for (local_i = 0; local_i < outl; local_i++) {
        local_c = out[local_i];
        if (local_c == '\n') {
            i = local_i;
            c = local_c;
            break;
        }
    }
    if (local_i == outl) {
        i = local_i;
        c = local_c;
    }
}
