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
    int temp_code = -1;
    int temp_len = 0;
    for (sym = 0; sym < alphabet_size; sym++) {
        if (code_lengths[sym] > 0) {
            temp_len++;
            temp_code = sym;
            if (temp_len > 1)
                break;
        }
    }
    len = temp_len;
    code = temp_code;
}
