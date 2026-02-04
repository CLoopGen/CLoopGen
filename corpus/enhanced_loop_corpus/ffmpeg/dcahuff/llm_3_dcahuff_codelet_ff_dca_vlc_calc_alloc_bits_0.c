#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t bitalloc_12_bits[5][12];
extern int *values;
extern uint8_t n;
extern uint8_t sel;
extern uint8_t i;
extern uint8_t id;
extern uint32_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access Pattern via Pointer Chasing
    // Use an auxiliary index array to indirectly access bitalloc_12_bits in non-sequential order.
    // Here, we simulate indirect access using a permutation of indices stored in a derived manner.
    int *index_map = (int*)malloc(n * sizeof(int));
    if (!index_map) return; // Handle allocation failure

    // Create an indirect access pattern: reverse order of values indices
    for (uint8_t j = 0; j < n; j++) {
        index_map[j] = n - 1 - j;
    }

    sum = 0; // Reset sum
    for (i = 0; i < n; i++) {
        uint8_t pos = index_map[i]; // Indirect lookup position
        if (values[pos] >= 1 && values[pos] <= 12) {
            id = values[pos] - 1;
            sum += bitalloc_12_bits[sel][id];
        }
    }

    free(index_map);
}
