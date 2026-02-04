#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int i;
extern int byte_abs_range;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp;
    for (i = 1; i < byte_abs_range / 2; i++) {
        temp = i;
        byte_abs[i] = temp;
        byte_abs[-i] = temp;
    }
}
