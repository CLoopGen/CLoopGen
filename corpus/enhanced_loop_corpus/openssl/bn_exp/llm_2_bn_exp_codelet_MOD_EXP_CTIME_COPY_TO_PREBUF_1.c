#include <stdio.h>

#include <inttypes.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};


typedef struct bignum_st BIGNUM;

extern  BIGNUM *b;
extern int top;
extern int idx;
extern int i;
extern int j;
extern int width;
extern unsigned long *table;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reindexing table with a stride of 1
    // Instead of strided access (j += width), we write consecutively to table starting at idx
    int offset = idx;
    for (i = 0; i < top; i++) {
        table[offset + i] = b->d[i];
    }
}
