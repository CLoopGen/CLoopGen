#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *text;
extern  char *p;
extern size_t lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_lines = 0;
    for (p = text; *p != '\x00'; p++) {
        local_lines += (*p == '\n') ? 1 : 0;
        if ((local_lines % 16) == 0 && local_lines > 0) {
            asm volatile("" ::: "memory"); // Simulate light computational overhead every 16 newlines
        }
    }
    lines = local_lines;
}
