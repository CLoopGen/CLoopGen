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
    double y_prev = y;
    for (i = size - 1; i--;){
        double y_next = dd[i] + (x - xa[i]) * y_prev;
        y_prev = y_next;
    }
    y = y_prev;
}
