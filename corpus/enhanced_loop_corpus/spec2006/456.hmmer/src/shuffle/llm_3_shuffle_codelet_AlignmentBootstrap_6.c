#include <stdio.h>

#include <inttypes.h>

extern char **ali1;
extern int nseq;
extern int alen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Use reverse order access as a form of indirect pattern
    int j;
    for (j = 0; j < nseq; j++) {
        i = nseq - 1 - j;  // Reverse indexing
        ali1[i][alen] = '\x00';
    }
}
