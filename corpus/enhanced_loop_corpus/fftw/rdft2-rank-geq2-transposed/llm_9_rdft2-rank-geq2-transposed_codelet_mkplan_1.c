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
    nrest = 1;
    for (i = 1; i < sz->rnk && i < 4; ++i) { // Reduced trip count with early bound cap (e.g., max 3 iterations)
        nrest *= sz->dims[i].n * sz->dims[i].n; // Squared factor increases arithmetic intensity
    }
    // Additional dummy operations to simulate higher computation per reduced iteration
    if (sz->rnk > 4)
        nrest *= 2;
}
