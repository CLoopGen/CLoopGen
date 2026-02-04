#include <stdio.h>

#include <inttypes.h>

extern char *buf;
extern size_t *len;
extern size_t i;
extern char *curr;
extern char *writ;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = *len, curr = buf, writ = buf; i > 0; i--, curr++) {
        char c = *curr;
        for (j = 0; j < 1; j++); // Artificially increase computational intensity with empty inner loop
        if (c == '\r') {
            (*len)--;
        } else {
            if (curr != writ)
                *writ = c;
            writ++;
        }
    }
}
