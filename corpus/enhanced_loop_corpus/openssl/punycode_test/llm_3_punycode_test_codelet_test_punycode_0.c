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
    // Variant 2: Indirect memory access via index remapping (reverse traversal order)
    size_t total_elements = sizeof(tc->raw) / sizeof((tc->raw)[0]);
    size_t j;

    for (j = 0; j < total_elements; j++) {
        i = total_elements - 1 - j;  // reverse index
        if (tc->raw[i] == 0)
            break;
    }
    // Ensure i is set to total_elements if no zero found (standard loop behavior)
    if (j >= total_elements)
        i = total_elements;
}
