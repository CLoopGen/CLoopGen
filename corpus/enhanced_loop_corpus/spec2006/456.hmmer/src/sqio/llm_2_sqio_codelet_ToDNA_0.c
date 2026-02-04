#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2), processing every second character
    // We assume the sequence is at least null-terminated and handle alignment by checking bounds
    int i = 0;
    for (; seq[i] != '\x00'; i += 2) {
        if (seq[i] == 'U')
            seq[i] = 'T';
        else if (seq[i] == 'u')
            seq[i] = 't';
    }
    // Handle odd-length sequences by processing last element if needed
    for (i = 1; seq[i] != '\x00'; i += 2) {
        if (seq[i] == 'U')
            seq[i] = 'T';
        else if (seq[i] == 'u')
            seq[i] = 't';
    }
}
