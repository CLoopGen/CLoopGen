#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;
extern int c;
extern char *q;
extern char str[512];
extern char *first_free_space;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < buf_size; i++) {
    c = buf[i];
    if (c == '\x00')
        break;
    if ((q - str) >= sizeof (str) - 1)
        break;
    if (c == ' ') {
        if (!first_free_space)
            first_free_space = q;
    } else {
        first_free_space = ((void *)0);
    }
    *q++ = c;
}

}
