#include <stdio.h>

#include <inttypes.h>

extern char *buf;
extern size_t *len;
extern size_t i;
extern char *curr;
extern char *writ;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char prev_char = '\0';
    for (i = *len, curr = buf, writ = buf; i > 0; i--, curr++) {
        char current = *curr;
        if (current == '\r') {
            (*len)--;
        } else {
            // Introduce artificial dependency: current output depends on previous input
            *writ = (prev_char == '\n' && current == '\n') ? '\n' : current;
            prev_char = current;
            writ++;
        }
    }
}
