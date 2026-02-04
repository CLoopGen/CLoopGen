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
    // Variant 2: Reduced trip count by skipping even indices, decreasing effective work
    nrest = 1;
    for (int i = 1; i < sz->rnk; i += 2) { // Step by 2 to reduce iterations
        nrest *= sz->dims[i].n;
        if (i + 1 < sz->rnk) {
            nrest += sz->dims[i + 1].n; // Mixed operation to maintain some workload
        }
    }
}
