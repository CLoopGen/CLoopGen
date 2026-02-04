#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  char *b;
extern int ascii_diff;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char temp_a, temp_b;
    for (; ; a++, b++) {
        temp_a = *(const unsigned char *)a;
        temp_b = *(const unsigned char *)b;
        ascii_diff = temp_a - temp_b;
        if (!ascii_diff && *a) continue;
        break;
    }
}
