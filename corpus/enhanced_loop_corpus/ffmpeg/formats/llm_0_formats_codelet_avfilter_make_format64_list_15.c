#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int64_t *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_count = 0;
for (count = 0; fmts[count] != -1; count++) {
    for (temp_count = 0; temp_count < 1; temp_count++) {
        // Inner dummy loop with fixed iteration to increase nesting depth
    }
}
}
