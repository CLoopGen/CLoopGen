#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

long *conflicts;
int allocno_row_words;
long *allocnos_live;
int j;
int ialloc_prod;

void init_vars() {
    allocno_row_words = 1024 * 1024 / sizeof(long); // ~8MB of data for long arrays
    ialloc_prod = 512;
    
    conflicts = (long*)calloc(allocno_row_words + ialloc_prod, sizeof(long));
    if (!conflicts) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    allocnos_live = (long*)calloc(allocno_row_words, sizeof(long));
    if (!allocnos_live) {
        fprintf(stderr, "Allocation failed\n");
        free(conflicts);
        exit(1);
    }
    
    for (int i = 0; i < allocno_row_words; i++) {
        allocnos_live[i] = (long)(i * 37 % 1000); // arbitrary non-zero pattern
    }
    
    for (int i = 0; i < ialloc_prod + allocno_row_words; i++) {
        conflicts[i] = (long)(i * 97 % 2000);
    }
}