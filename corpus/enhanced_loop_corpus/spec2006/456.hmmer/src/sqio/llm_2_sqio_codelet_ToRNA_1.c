#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (int i = 0; seq[i] != '\x00'; i += 2) {
        if (seq[i] == 'T')
            seq[i] = 'U';
        else if (seq[i] == 't')
            seq[i] = 'u';
    }
}
