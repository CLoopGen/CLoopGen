#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ep;
extern  char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_cp = cp;
    for (; temp_cp < ep && *temp_cp != '\x00'; temp_cp++) {
        cp = temp_cp + 1; // Introduce WAW dependency: cp is updated in every iteration, but original cp is only read at start
    }
}
