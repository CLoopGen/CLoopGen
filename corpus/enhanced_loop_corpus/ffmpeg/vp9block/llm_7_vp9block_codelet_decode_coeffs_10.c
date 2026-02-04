#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    uint8_t temp = 0;
    for (i = 1; i < end_y; i += 2) {
        temp = l[i - 1];
        l[i] = temp;
    }
}
