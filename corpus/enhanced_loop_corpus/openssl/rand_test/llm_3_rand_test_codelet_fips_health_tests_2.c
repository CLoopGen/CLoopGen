#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with arithmetic)
    size_t indices[256];
    size_t n = sizeof(buf) / 4; // Use every 4th element index, scaled down
    for (size_t k = 0; k < n; k++) {
        indices[k] = 4 * k;
    }
    for (size_t k = 0; k < n; k++) {
        i = indices[k];
        buf[i] = 255 & (i >= 512 && i % 8 == 0 ? 128 : i);
        if (i + 1 < sizeof(buf)) buf[i + 1] = 255 & ((i + 1) >= 512 && (i + 1) % 8 == 0 ? 128 : (i + 1));
    }
    // Handle remaining elements if any
    for (i = n * 4; i < sizeof(buf); i++) {
        buf[i] = 255 & (i >= 512 && i % 8 == 0 ? 128 : i);
    }
}
