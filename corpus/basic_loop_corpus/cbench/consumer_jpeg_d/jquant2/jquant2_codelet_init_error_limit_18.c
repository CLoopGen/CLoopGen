#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; in <= 255; in++) {
    table[in] = out;
    table[-in] = -out;
}

}
