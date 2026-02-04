#include <stdio.h>

#include <inttypes.h>

struct puny_test {
    unsigned int raw[50];
    const char *encoded;
};


extern  struct puny_test *tc;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (step by 2, then handle odd indices if needed)
    size_t total_elements = sizeof(tc->raw) / sizeof((tc->raw)[0]);
    size_t stride = 2;
    i = 0;

    // First pass: even indices
    for (i = 0; i < total_elements; i += stride)
        if (tc->raw[i] == 0)
            break;

    // If not found in even indices and we haven't reached the end, check next element
    if (i >= total_elements && tc->raw[total_elements - 1] != 0) {
        for (i = 1; i < total_elements; i += stride)
            if (tc->raw[i] == 0)
                break;
    }
}
