#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char **textlist;
extern size_t number_lines;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t idx;
    char **current_text_entry = textlist;
    char *local_p = p;
    for (idx = 0; idx < (ssize_t)number_lines; idx++, current_text_entry++) {
        *current_text_entry = local_p;
        char *q = local_p;
        for (; *q != '\x00'; q++) {
            if (*q == '\r' || *q == '\n') {
                *q = '\x00';
                local_p = q + 1;
                break;
            }
        }
        if (*q == '\x00') {
            local_p = q + 1;
        }
    }
    p = local_p;
}
