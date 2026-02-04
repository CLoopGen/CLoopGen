#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int response_codes[];
extern int err;
extern int i;
extern int result;
extern int code_found;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate index array simulation
    int *ptr = response_codes;
    for (i = 0; *(ptr + i); ++i) {
        if (err == *(ptr + i)) {
            code_found = 1;
            result = err;
            break;
        }
    }
}
