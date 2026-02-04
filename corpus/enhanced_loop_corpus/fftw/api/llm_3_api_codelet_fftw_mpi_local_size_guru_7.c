#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT b[2];
} ddim;

typedef struct {
    int rnk;
    ddim dims[1];
} dtensor;

extern int i;
extern dtensor *sz;
extern INT Nafter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — access every second element, simulating strided pattern
    // This assumes rnk is even and at least 4 for meaningful behavior
    for (i = 2; i < sz->rnk; i += 2)
        Nafter *= sz->dims[i].n;
    // Handle remaining element if rnk is odd
    if (sz->rnk % 2 == 1 && sz->rnk > 2)
        Nafter *= sz->dims[sz->rnk - 1].n;
}
