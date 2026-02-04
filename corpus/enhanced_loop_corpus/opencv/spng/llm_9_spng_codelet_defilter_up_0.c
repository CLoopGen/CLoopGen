#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t bytes;
extern unsigned char *row;
extern  unsigned char *prev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < bytes * 2; i++) {
        size_t idx = i / 2;
        row[idx] += prev[idx] + 1;
    }
}
