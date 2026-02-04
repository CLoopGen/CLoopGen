#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = out;
    for (; in <= 255; in++) {
        table[in] = temp;
        if (in != 0) {
            table[-in] = -temp;
        }
    }
}
