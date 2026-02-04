#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t (*tab)[2];
extern int size;
extern int a;
extern int b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using pointer arithmetic to simulate indirect indexing
    // We use a pointer to walk through the 'tab' array elements instead of direct indexing
    uint16_t (*p)[2] = tab;
    for (i = 0; i < size && !((*p)[0] == a && (*p)[1] == b); i++, p++)
        ;
}
