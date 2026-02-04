#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double dd[];
extern  double xa[];
extern  size_t size;
extern  double x;
extern size_t i;
extern double y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access but starting from the middle and unrolling by 2
    size_t mid = size / 2;
    for (i = mid; i-- > 0; ) {
        y = dd[i] + (x - xa[i]) * y;
        if (mid + i < size) {
            y = dd[mid + i] + (x - xa[mid + i]) * y;
        }
    }
}
