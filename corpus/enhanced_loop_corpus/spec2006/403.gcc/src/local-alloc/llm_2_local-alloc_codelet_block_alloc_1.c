#include <stdio.h>

#include <inttypes.h>

extern int next_qty;
extern int i;
extern int *qty_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < next_qty; i += 2)
        qty_order[i] = i;
    for (i = 1; i < next_qty; i += 2)
        qty_order[i] = i;
}
