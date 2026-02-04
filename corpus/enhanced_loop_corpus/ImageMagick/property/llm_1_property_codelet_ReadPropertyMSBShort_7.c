#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char **p;
extern size_t *length;
extern int c;
extern ssize_t i;
extern unsigned char buffer[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i += 2) {
        if (i + 0 < 2) {
            c = (int)(*(*p)++);
            (*length)--;
            buffer[i + 0] = (unsigned char)c;
        }
        if (i + 1 < 2) {
            c = (int)(*(*p)++);
            (*length)--;
            buffer[i + 1] = (unsigned char)c;
        }
    }
}
