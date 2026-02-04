#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT is;
    INT os;
} iodim;

typedef struct {
    int rnk;
    iodim dims[1];
} tensor;

extern tensor *sz;
extern int i;
extern INT nrest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering dimensions to access in increasing stride order
    INT temp = 1;
    for (int j = sz->rnk - 1; j >= 1; --j)
        temp *= sz->dims[j].n;
    nrest = temp;
}
