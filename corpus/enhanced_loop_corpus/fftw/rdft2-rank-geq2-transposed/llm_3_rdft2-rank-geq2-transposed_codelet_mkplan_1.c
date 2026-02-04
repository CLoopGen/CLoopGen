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
    // Variant 2: Strided access with step size greater than 1, processing every second dimension starting from index 1
    nrest = 1;
    for (int j = 1; j < sz->rnk; j += 2)  // Stride of 2 in loop index
        nrest *= sz->dims[j].n;
}
