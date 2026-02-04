#include <stdio.h>

#include <inttypes.h>

extern int next_qty;
extern int i;
extern int *qty_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[2] = {1, 0};
    for (i = 0; i < next_qty; i++)
        qty_order[i] = indices[i % 2] + (i / 2) * 2;
}
