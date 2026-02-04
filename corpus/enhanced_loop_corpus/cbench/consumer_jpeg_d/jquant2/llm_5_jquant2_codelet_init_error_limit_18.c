#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; in <= 255; in++) {
    if (in < 100) {
        table[in] = out;
        table[-in] = -out;
    } else {
        table[in] = out * 2;
        table[-in] = -out * 2;
    }
}
}
