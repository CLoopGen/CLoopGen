#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t k;
extern size_t *data;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via offset)
    size_t *index_map = malloc(k * sizeof(size_t));
    if (!index_map) return;
    for (size_t idx = 0; idx < k; idx++) {
        index_map[idx] = (idx * 3 + 1) % k; // Generate scattered indices
    }
    for (; i < k - 1; i++) {
        size_t curr = index_map[i];
        size_t next = index_map[i + 1];
        if (next < k && curr < k) {
            data[next] = data[curr] + 1;
        }
    }
    free(index_map);
}
