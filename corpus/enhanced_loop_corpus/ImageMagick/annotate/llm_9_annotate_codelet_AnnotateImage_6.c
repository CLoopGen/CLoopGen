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
    ssize_t i;
    for (i = 0; i < (ssize_t)(number_lines > 0 ? number_lines / 2 : 0); i++) {
        char *q;
        textlist[2 * i] = p;
        for (q = p; *q != '\x00'; q++) {
            if ((*q == '\r') || (*q == '\n')) {
                break;
            }
        }
        if (*q == '\r') {
            *q = '\x00';
            q++;
        }
        *q = '\x00';
        p = q + 1;

        if (2 * i + 1 < (ssize_t)number_lines) {
            textlist[2 * i + 1] = p;
            for (q = p; *q != '\x00'; q++) {
                if ((*q == '\r') || (*q == '\n')) {
                    break;
                }
            }
            if (*q == '\r') {
                *q = '\x00';
                q++;
            }
            *q = '\x00';
            p = q + 1;
        }
    }
}
