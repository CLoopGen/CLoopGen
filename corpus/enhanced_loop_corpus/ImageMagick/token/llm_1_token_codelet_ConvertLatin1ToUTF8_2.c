#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char* temp_p;
    for (p = content; *p != '\x00'; p++) {
        length += 1;
        if ((*p & 128) != 0) {
            for (temp_p = p; temp_p < p + 1; temp_p++) {
                length += 1;
            }
        }
    }
}
