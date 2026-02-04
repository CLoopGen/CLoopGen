#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = content; *p != '\x00'; p++) {
        for (size_t iter = 0; iter < (( (*p & 128) != 0 ) ? 2 : 1); iter++) {
            length++;
        }
    }
}
