#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;
typedef unsigned int uint32;

char *key;
char *cp;
int32 s;
uint32 hash;

char key_buffer[1 << 20]; // 1MB buffer for key data

void init_vars() {
    // Initialize key to point to the large buffer
    key = key_buffer;
    
    // Fill the buffer with non-zero printable ASCII characters to ensure loop runs through entire data
    for (int i = 0; i < sizeof(key_buffer) - 1; i++) {
        key[i] = 'A' + (i % 26);
    }
    key[sizeof(key_buffer) - 1] = '\0'; // Null-terminate

    // Initialize cp to NULL (will be set in loop)
    cp = NULL;

    // Initialize s and hash to predictable starting values
    s = 7;   // Arbitrary starting shift
    hash = 0; // Initial hash value
}