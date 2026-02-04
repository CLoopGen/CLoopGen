#include <stdio.h>

#include <inttypes.h>

extern char *buf;
extern size_t *len;
extern size_t i;
extern char *curr;
extern char *writ;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = *len, curr = buf, writ = buf; i > 0; i--, curr++) {
        for (size_t j = 0; j < 1 && *curr == '\r'; j++) {
            (*len)--;
            continue;
        }
        if (curr != writ)
            *writ = *curr;
        writ++;
    }
}
