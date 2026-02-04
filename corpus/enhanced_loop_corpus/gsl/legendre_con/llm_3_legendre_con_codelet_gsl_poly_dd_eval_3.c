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
    // Variant 2: Consecutive reverse access but unrolled by a factor of 2 for improved locality and reduced loop overhead
    // Handles both even and odd size cases correctly
    size_t n = size - 1;
    if (n % 2 == 1) {
        y = dd[n] + (x - xa[n]) * y;
        n--;
    }
    for (; n >= 2; n -= 2) {
        y = dd[n] + (x - xa[n]) * y;
        y = dd[n-1] + (x - xa[n-1]) * y;
    }
    // Handle remaining element at index 0 if needed
    if (n == 0)
        y = dd[0] + (x - xa[0]) * y;
}
