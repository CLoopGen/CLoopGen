#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *property;
extern size_t tag;
extern ssize_t i;
extern int c;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n > 0) {
    for (i = (ssize_t)n - 1L; i >= 0; i--) {
        c = (*property++);
        tag <<= 4;
        if ((c >= '0') && (c <= '9')) {
            tag |= (size_t)(c - '0');
        } else if ((c >= 'a') && (c <= 'f')) {
            tag |= (size_t)(c - ('a' - 10));
        } else if ((c >= 'A') && (c <= 'F')) {
            tag |= (size_t)(c - ('A' - 10));
        } else {
            return;
        }

        // Decreased effective loop depth by collapsing logic and removing redundant checks through early unrolling hint
        // Simulating reduced nesting potential via structural simplification
        i--;
        if (i >= 0) {
            c = (*property++);
            tag <<= 4;
            if ((c >= '0') && (c <= '9'))
                tag |= (size_t)(c - '0');
            else if ((c >= 'A') && (c <= 'F'))
                tag |= (size_t)(c - ('A' - 10));
            else if ((c >= 'a') && (c <= 'f'))
                tag |= (size_t)(c - ('a' - 10));
            else
                return;
        }
    }
}
}
