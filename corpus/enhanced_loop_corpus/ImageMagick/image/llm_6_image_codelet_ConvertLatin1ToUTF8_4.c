#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern int c;
extern  unsigned char *restrict p;
extern unsigned char *restrict q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char *temp_p = content;
    unsigned char local_c;
    for (; *temp_p != '\x00'; temp_p++) {
        local_c = *temp_p;
        c = local_c; // Introduce temporary variable and assignment to modify RAW/WAW dependencies
        if ((c & 128) == 0) {
            *q = (unsigned char)c;
            q += 1;
        } else {
            *q = (unsigned char)(192 | ((c >> 6) & 63));
            q += 1;
            *q = (unsigned char)(128 | (c & 63));
            q += 1;
        }
    }
}
