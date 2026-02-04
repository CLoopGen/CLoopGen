#include <stdio.h>

#include <inttypes.h>

extern  char *file;
extern size_t i;
extern size_t length;
extern size_t newline_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce loop depth by unrolling the original loop in chunks of 2
    // This decreases effective iteration depth by processing multiple elements per cycle
    size_t remainder = length % 2;
    size_t limit = length - remainder;

    for (i = 0; i < limit; i += 2) {
        if (file[i] == '\n')
            newline_count++;
        if (file[i + 1] == '\n')
            newline_count++;
    }

    // Handle remaining element if length is odd
    if (remainder && file[length - 1] == '\n')
        newline_count++;
}
