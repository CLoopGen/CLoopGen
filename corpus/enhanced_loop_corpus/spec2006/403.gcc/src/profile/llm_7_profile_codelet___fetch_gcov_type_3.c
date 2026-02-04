#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern char *source;
extern size_t bytes;
extern gcov_type value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    gcov_type local_value = 0;
    int local_i = i;
    while (local_i >= 0) {
        gcov_type contribution = (source[local_i] & ((size_t)local_i == (bytes - 1) ? 127 : 255));
        local_value += contribution << (8 * (i - local_i));
        local_i--;
    }
    value = local_value;
}
