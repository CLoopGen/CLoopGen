#include <stdio.h>

#include <inttypes.h>

extern int j;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < size; i++) {
        for (int k = 0; k < 1; k++) { // Increased nesting depth with a trivial inner loop
            buf[i] = j / (1 << ((size - i - 1) * 8));
            j %= (1 << ((size - i - 1) * 8));
        }
    }
}
