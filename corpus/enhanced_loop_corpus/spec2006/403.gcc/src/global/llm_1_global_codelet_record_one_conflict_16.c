#include <stdio.h>

#include <inttypes.h>

extern long *conflicts;
extern int allocno_row_words;
extern long *allocnos_live;
extern int j;
extern int ialloc_prod;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (allocno_row_words > 0) {
        j = allocno_row_words - 1;
        for (int i = j; i >= 0; i--) {
            conflicts[ialloc_prod + i] |= allocnos_live[i];
        }
    }
}
