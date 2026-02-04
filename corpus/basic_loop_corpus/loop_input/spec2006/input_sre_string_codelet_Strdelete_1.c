#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s1;
int pos;
char *s;

#define DATA_SIZE (128 << 20)  // 128 MB

static char data[DATA_SIZE];

void init_vars() {
    // Initialize the global data buffer with printable characters and a terminator at the end
    for (size_t i = 0; i < DATA_SIZE - 1; i++) {
        data[i] = 'A' + (i % 26);
    }
    data[DATA_SIZE - 1] = '\0';  // Ensure null termination

    // Set s1 to point to the data array
    s1 = data;

    // Set pos to a valid starting offset (e.g., middle of the array to allow forward traversal)
    pos = DATA_SIZE / 4;

    // Ensure that from s1+pos onward, there are enough elements so that *s and *(s+1) are valid until the null terminator
    // Since the loop stops when *s is '\0', and we have set the last element to '\0', it's safe
    s = NULL;  // Will be set in loop(), not initialized here
}