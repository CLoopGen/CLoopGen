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
    uint8_t local_c;
    int local_i;
    char *local_q = q;
    char *local_first_free_space = first_free_space;
    for (i = 0; i < buf_size; i++) {
        local_i = i;
        local_c = buf[local_i];
        if (local_c == '\x00')
            break;
        if ((local_q - str) >= sizeof(str) - 1)
            break;
        if (local_c == ' ') {
            if (!local_first_free_space)
                local_first_free_space = local_q;
        } else {
            local_first_free_space = ((void *)0);
        }
        *local_q++ = local_c;
    }
    q = local_q;
    first_free_space = local_first_free_space;
}
