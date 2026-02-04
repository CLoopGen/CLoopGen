#include <stdio.h>

#include <inttypes.h>

extern long *conflicts;
extern int allocno_row_words;
extern long *allocnos_live;
extern int j;
extern int ialloc_prod;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = allocno_row_words - 1;
    for (j = start; j >= 0; j -= 2) {
        conflicts[ialloc_prod + j] |= allocnos_live[j];
        if (j > 0) {
            conflicts[ialloc_prod + j - 1] |= allocnos_live[j - 1];
        }
    }
}
