#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with unrolling (access two elements per iteration)
    for (i = 1; i < buf_size - 1; i += 2) {
        uint8_t current = buf[i];
        uint8_t prev = buf[i - 1];
        uint8_t next = buf[i + 1];

        if (current == 119 || current == 11) {
            if ((current ^ prev) == (119 ^ 11)) {
                i--;
                break;
            } else if ((current ^ next) == (119 ^ 11)) {
                break;
            }
        }
    }
}
