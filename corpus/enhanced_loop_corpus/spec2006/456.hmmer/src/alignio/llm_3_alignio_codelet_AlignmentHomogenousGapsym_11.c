#include <stdio.h>

#include <inttypes.h>

extern char **aseq;
extern int nseq;
extern int alen;
extern char gapsym;
extern int i;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Pointer Arithmetic
    // Use pointer arithmetic to indirectly access elements, simulating indirect or computed indexing
    // Each sequence is accessed via a pointer, and each character within the sequence is accessed using offset arithmetic.
    char **seq_ptr = aseq;
    for (i = 0; i < nseq; i++) {
        char *seq_base = seq_ptr[i];
        for (apos = 0; apos < alen; apos++) {
            char val = *(seq_base + apos);
            if (val == ' ' || val == '.' || val == '_' || val == '-' || val == '~')
                *(seq_base + apos) = gapsym;
        }
    }
}
