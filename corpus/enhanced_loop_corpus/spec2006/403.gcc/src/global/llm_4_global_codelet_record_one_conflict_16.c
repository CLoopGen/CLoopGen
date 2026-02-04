#include <stdio.h>

#include <inttypes.h>

extern long *conflicts;
extern int allocno_row_words;
extern long *allocnos_live;
extern int j;
extern int ialloc_prod;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = allocno_row_words - 1; j >= 0; j--) {
        if (!(allocnos_live[j])) continue;
        conflicts[ialloc_prod + j] |= allocnos_live[j];
    }
}
