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
    // Variant 1: Consecutive memory access by unrolling and accessing elements in increasing order
    INT product = 1;
    for (int j = 1; j < sz->rnk; ++j) {
        product *= sz->dims[j].n;
    }
    nrest = product;
}
