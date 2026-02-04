#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *keyword;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal with forward semantic preservation
    int start = 0;
    for (i = 7; i >= 0; i--) {
        if (ptr8[i] == ' ') {
            start = i + 1;
            break;
        }
    }
    for (i = start; i < 8; i++) {
        keyword[i - start] = ptr8[i];
    }
    // Adjust global `i` to reflect original behavior at loop exit
    i = start;
}
