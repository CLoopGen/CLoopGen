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
    len = 0;
    code = -1;
    for (sym = 0; sym < alphabet_size * 2; sym += 2) {
        int index = sym % alphabet_size;
        if (code_lengths[index] > 0) {
            len++;
            code = index;
            if (len >= 3) {
                break;
            }
        }
    }
}
