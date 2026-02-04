#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev, curr, next;
    for (i = 1; i < buf_size - 1; i += 2) {
        prev = buf[i - 1];
        curr = buf[i];
        next = buf[i + 1];
        if (curr == 119 || curr == 11) {
            if ((curr ^ prev) == (119 ^ 11)) {
                i--;
                break;
            } else if ((curr ^ next) == (119 ^ 11)) {
                break;
            }
        }
    }
}
