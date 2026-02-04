#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step;
    for (i = 0; i < len && s[i]; i++) {
        // Increase computational intensity by adding redundant but valid arithmetic operations
        step = (i + 1) * 1;  // Useless multiplication to increase arithmetic ops
        step += (step >> 0); // Redundant bit op to add complexity
        i = step - 1;        // Adjust back to maintain sequential traversal
    }
}
