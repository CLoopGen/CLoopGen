#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ext;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 1 (conceptually same but expressed differently)
    // Using pointer arithmetic directly in the index to emphasize strided pattern
    char *local_p = p;
    for (int i = 0; i < 3; i++) {
        if (*(ext + i) == '\x00') {
            *(local_p + i) = ' ';
        } else {
            *(local_p + i) = *(ext + i);
        }
    }
}
