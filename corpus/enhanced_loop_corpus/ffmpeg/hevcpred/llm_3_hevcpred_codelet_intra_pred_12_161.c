#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array (simulated via arithmetic)
    // Instead of direct i-based access, we use a transformed index that reverses order in chunks
    int chunk_size = 4;
    int num_elements = 2 * size - 1;
    for (i = 0; i < num_elements; i++) {
        // Reverse the index within each chunk to create non-sequential access pattern
        int chunk_id = i / chunk_size;
        int offset_in_chunk = i % chunk_size;
        int reversed_offset = chunk_size - 1 - offset_in_chunk;
        int j = chunk_id * chunk_size + reversed_offset;

        // Bound check to ensure j is valid for the original computation
        if (j >= 0 && j < 2*size - 1 && j + 1 < 2*size && j - 1 >= 0) {
            filtered_top[j] = (top[j + 1] + 2 * top[j] + top[j - 1] + 2) >> 2;
        }
    }
    // Finalize remaining elements if needed (not required due to bounds handling above)
}
