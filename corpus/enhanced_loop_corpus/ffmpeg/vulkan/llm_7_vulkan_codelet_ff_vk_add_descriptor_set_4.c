#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[2] = {0, 1};
    for (int i = 0; i < num; i++) {
        arr[i % 2] = i * 2;
    }
    // Creates a loop-carried WAW (write-after-write) dependency on alternating elements of `arr`.
    // Iterations writing to the same index have write conflicts, enforcing ordering within each stream.
    // Also introduces modulo indexing to create non-trivial access pattern without pointer aliasing issues.
}
