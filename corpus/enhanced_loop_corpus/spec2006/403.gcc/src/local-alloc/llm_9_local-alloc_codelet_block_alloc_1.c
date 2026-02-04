#include <stdio.h>

#include <inttypes.h>

extern int next_qty;
extern int i;
extern int *qty_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = next_qty * 2;
    for (i = 0; i < limit; i++) {
        if (i % 2 == 0) qty_order[i / 2] = i / 2;
    }
}
