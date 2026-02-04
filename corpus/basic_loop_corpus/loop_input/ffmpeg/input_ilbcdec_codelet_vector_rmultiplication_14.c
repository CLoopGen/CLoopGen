#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int16_t *in;
int16_t *win;
int length;
int shift;

void init_vars() {
    length = 1 << 20; // Approximately 1MB of data (1M int16_t elements = 2MB per array)
    shift = 4; // Arbitrary valid shift value

    in = (int16_t*)aligned_alloc(32, length * sizeof(int16_t));
    out = (int16_t*)aligned_alloc(32, length * sizeof(int16_t));
    win = (int16_t*)aligned_alloc(32, (length) * sizeof(int16_t)); // Ensure win[-i] for i up to length-1 is valid

    // Initialize input and window arrays
    for (int i = 0; i < length; i++) {
        in[i] = rand() % 65536 - 32768;
        win[i] = rand() % 65536 - 32768;
    }

    // Note: win[-i] accesses negative indices, so we must ensure that the base pointer win
    // points at least 'length' elements past the start of allocated storage.
    // We reallocate and adjust win to point into the middle.

    int16_t* temp = (int16_t*)aligned_alloc(32, 2 * length * sizeof(int16_t));
    for (int i = 0; i < length; i++) {
        temp[length + i] = win[i]; // copy original win content to upper half
        temp[i] = rand() % 65536 - 32768; // initialize lower half for negative indexing
    }
    free(win);
    win = &temp[length]; // Now win[0] is temp[length], so win[-i] for i in [0, length) is valid
}