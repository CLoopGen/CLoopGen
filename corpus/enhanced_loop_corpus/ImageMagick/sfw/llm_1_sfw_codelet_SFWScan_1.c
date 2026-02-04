#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *p;
extern  unsigned char *target;
extern  size_t length;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)length && p[i] == target[i]; i++) {
        // Condition moved into loop header to eliminate explicit 'break', reducing effective loop body complexity
        // This flattens the control flow and reduces branching inside the loop body
    }
}
