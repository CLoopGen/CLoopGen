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
    int local_len = len;
    for (sym = 0; sym < alphabet_size; sym++) {
        int cl = code_lengths[sym];
        if (cl > 0) {
            local_len++;
            if (local_len == 1) {
                code = sym;
            } else {
                code = sym;
                len = local_len;
                break;
            }
        }
    }
    if (local_len > len) {
        len = local_len;
    }
}
