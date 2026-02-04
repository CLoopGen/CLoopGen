#include <stdio.h>
#include <inttypes.h>

char *type;

void init_vars() {
    // Allocate a large buffer to ensure loop runs for ~0.01 seconds
    // Assuming typical CPU can scan ~1-2 GB/s, use 10-20 MB of whitespace
    static char type_buffer[16 * 1024 * 1024]; // 16 MB

    // Fill buffer with spaces and terminate with non-whitespace
    for (size_t i = 0; i < sizeof(type_buffer) - 1; i++) {
        type_buffer[i] = ' ';
    }
    type_buffer[sizeof(type_buffer) - 1] = 'x'; // Non-whitespace to break loop

    // Initialize external pointer to point just before the buffer start
    // so that after first increment in loop, it points to buffer[0]
    type = type_buffer - 1;
}