#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *p;
extern unsigned char *utf8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char *local_p = utf8;
    unsigned char current;
    for (; (current = *local_p), current != '\x00'; local_p++) {
        if ((current < 32) && (current != 9) && (current != 10) && (current != 13)) {
            p = local_p;
            break;
        }
    }
    if (*local_p == '\x00') {
        p = local_p;
    }
}
