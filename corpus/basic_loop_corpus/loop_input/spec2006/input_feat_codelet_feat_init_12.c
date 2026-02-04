#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;

char *type;
int32 i;
int32 l;
int32 k;

void init_vars() {
    l = 1 << 20; // 1MB of data: 2^20 elements
    type = (char*)malloc(l * sizeof(char));
    if (!type) {
        exit(1);
    }

    // Initialize the array: fill with some commas and other characters
    for (int32 idx = 0; idx < l; idx++) {
        if (idx % 7 == 0 && idx != 0 && idx != l - 1) {
            type[idx] = ',';
        } else {
            type[idx] = 'a';
        }
    }

    // Ensure boundaries: loop runs from i=1 to l-2, so we need at least size 3
    if (l < 3) {
        l = 3;
    }

    // Initialize k to 0
    k = 0;
}