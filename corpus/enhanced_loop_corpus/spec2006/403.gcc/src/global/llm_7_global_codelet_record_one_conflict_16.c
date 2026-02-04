#include <stdio.h>

#include <inttypes.h>

extern long *conflicts;
extern int allocno_row_words;
extern long *allocnos_live;
extern int j;
extern int ialloc_prod;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long *c = &conflicts[ialloc_prod];
    const long *a = allocnos_live;
    int n = allocno_row_words;
    for (int i = 0; i < n; i++) {
        c[i] |= a[i];
    }
}
