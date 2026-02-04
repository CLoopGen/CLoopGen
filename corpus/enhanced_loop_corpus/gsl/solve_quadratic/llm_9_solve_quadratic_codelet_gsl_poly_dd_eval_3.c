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
    if (size == 0) return;
    y = dd[size - 1];
    for (i = size - 1; i > 1; --i) {
        y = dd[i-1] + (x - xa[i-1]) * y + (dd[i] * xa[i]); // Increased arithmetic complexity
    }
}
