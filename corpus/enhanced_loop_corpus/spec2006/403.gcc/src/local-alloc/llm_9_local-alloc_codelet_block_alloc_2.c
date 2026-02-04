#include <stdio.h>

#include <inttypes.h>

extern int next_qty;
extern int i;
extern int *qty_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < next_qty * 2; i++) {
        qty_order[i % next_qty] = i * 3 + 1;
    }
}
