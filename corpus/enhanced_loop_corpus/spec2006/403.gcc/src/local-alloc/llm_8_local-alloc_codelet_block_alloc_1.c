#include <stdio.h>

#include <inttypes.h>

extern int next_qty;
extern int i;
extern int *qty_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < next_qty; i += 2) {
        if (i < next_qty) qty_order[i] = i;
        if (i + 1 < next_qty) qty_order[i + 1] = i + 1;
    }
}
