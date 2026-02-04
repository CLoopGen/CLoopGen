#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using array indexing with step-1, but unrolled by factor 2
    int i;
    for (i = 0; seq[i + 1] != '\x00'; i += 2) {
        if (seq[i] == 'T')
            seq[i] = 'U';
        else if (seq[i] == 't')
            seq[i] = 'u';

        if (seq[i + 1] == 'T')
            seq[i + 1] = 'U';
        else if (seq[i + 1] == 't')
            seq[i + 1] = 'u';
    }
    // Handle last element if needed
    if (seq[i] != '\x00') {
        if (seq[i] == 'T')
            seq[i] = 'U';
        else if (seq[i] == 't')
            seq[i] = 'u';
    }
}
