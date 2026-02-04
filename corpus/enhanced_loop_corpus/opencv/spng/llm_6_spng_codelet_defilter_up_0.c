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
    size_t j;
    for (j = 0; j < bytes; j++) {
        unsigned char temp = prev[j];
        row[j] = row[j] + temp;
    }
}
