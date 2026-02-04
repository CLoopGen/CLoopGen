#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern char *source;
extern size_t bytes;
extern gcov_type value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    gcov_type temp_value = value;
    for (int j = i; j >= 0; j--) {
        temp_value = temp_value * 256 + (source[j] & ((size_t)j == (bytes - 1) ? 127 : 255));
    }
    value = temp_value;
}
