#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
int i;

static char data[1024 * 128]; // 128KB buffer

void init_vars() {
    // Initialize the data array with digits followed by a non-digit
    for (size_t j = 0; j < sizeof(data) - 1; j++) {
        data[j] = '0' + (j % 10); // cycle through '0' to '9'
    }
    data[sizeof(data) - 1] = 'A'; // ensure termination by a non-digit

    // Initialize pointer s to point to the data array
    s = data;

    // Initialize loop index i to 0
    i = 0;
}