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
    double acc = 0.0;
    for (i = 0; i < size; i++)
        acc += dd[i] * (x - xa[i]);
    y = acc;
}
