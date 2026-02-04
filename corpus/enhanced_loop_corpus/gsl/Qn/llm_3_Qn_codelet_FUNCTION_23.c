#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer chasing
    // Use an index array that creates indirect access into left[] and right[]
    // Simulate a linked structure using the arrays by treating 'right' as next pointers in a chain
    // Traverse a subset of indices indirectly through a chain starting from index 1
    int current = 1;
    while (current < ni && current >= 0) {
        int jj;
        for (jj = left[current]; jj <= right[current]; ++jj) {
            j++;
        }
        // Use a deterministic indirect step: jump to right[current] % ni if valid
        int next = right[current] % ni;
        if (next <= current) break; // Prevent infinite loops or cycles
        current = next;
    }
}
