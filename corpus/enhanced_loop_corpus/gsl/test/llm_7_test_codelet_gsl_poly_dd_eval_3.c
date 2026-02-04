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
    double coeff = 1.0;
    for (i = size - 1; i--;){
        acc += dd[i] * coeff;
        coeff *= (x - xa[i]);
    }
    y = acc + coeff * y;
}
