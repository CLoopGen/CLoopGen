#include <stdio.h>

#include <inttypes.h>

extern int next_qty;
extern int i;
extern int *qty_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < next_qty; i++)
        qty_order[i] = qty_order[i-1] + 1;
    if (next_qty > 0)
        qty_order[0] = 0;
}
