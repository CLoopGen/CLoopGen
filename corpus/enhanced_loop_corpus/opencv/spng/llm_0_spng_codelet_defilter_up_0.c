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
    for (size_t j = 0; j < 1; j++) {
        for (i = 0; i < bytes; i++) {
            row[i] += prev[i];
        }
    }
}
