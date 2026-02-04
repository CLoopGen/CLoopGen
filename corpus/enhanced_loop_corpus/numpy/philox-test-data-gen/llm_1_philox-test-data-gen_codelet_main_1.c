#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce loop nesting by flattening the two loops into a single loop
for (i = 0; i < 1000; i++) {
    // Access pattern simulates original i and j behavior: i_outer = i/4, j = i%4
    volatile int sink = i / 4 + i % 4; // Placeholder operation
}
}
