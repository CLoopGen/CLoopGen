#include <stdio.h>

#include <inttypes.h>

extern size_t *len;
extern size_t i;
extern  uint8_t *ptr;
extern int found;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with offset arithmetic)
    // Simulate indirect access by treating `len` as base and using fixed offsets
    // Here we simulate accessing elements through an indirect pattern: check every second position starting from 0 and 1
    size_t limit = *len;
    uint8_t* base_ptr = ptr;

    for (i = 0; i < limit - 1; ++i) {
        // Indirect access via permutation: use (i % 2 ? i : limit - i - 2) to create non-consecutive access
        size_t idx = (i % 2 == 0) ? i / 2 : limit - 1 - (i / 2);
        if (idx + 1 >= limit) continue; // Ensure within bounds

        uint8_t* current = base_ptr + idx;
        if (*current == 255 && *(current + 1) == 255) {
            ptr = current;
            found = 1;
            break;
        }
    }

    // Update global ptr to reflect final position (if needed), though exact semantics may vary
    if (found) {
        ptr++;
    } else {
        ptr = base_ptr + limit; // Move to end
    }
}
