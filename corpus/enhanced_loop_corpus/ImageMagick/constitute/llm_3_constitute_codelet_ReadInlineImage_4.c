#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *p;
extern char *q;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal from a calculated start point
    // Assumes p points into a buffer; we back up to simulate reverse access over a segment
    char *start = p - (4096 - 6) + 1;  // approximate start of relevant segment
    char *src = p;
    char *dst = q;

    // Move pointers backward consecutively, processing up to (4096 - 6) bytes or until ';' or '\0' is found
    for (i = 0; i < (4096 - 6); i++) {
        if (*src == ';' || *src == '\x00') break;
        src--;
        dst--;
        *dst = *src;
    }

    // Adjust original pointers to reflect final positions (side-effect consistency)
    p = src;
    q = dst;
}
