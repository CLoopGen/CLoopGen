#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern char **irow;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element forward and backward)
    for (i = 0; i < 6; i += 2) {
        irow[i] = row[i];
    }
    for (i = 5; i >= 1; i -= 2) {
        irow[i] = row[i];
    }
}
