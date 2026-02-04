#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct DWTCompose {
    uint8_t *b[8];
    int y;
} DWTCompose;

extern DWTCompose *cs;
extern int i;
extern uint8_t *b[10];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive reverse-order memory access
    for (i = 0; i < 8; i++) {
        int rev_index = 7 - i;  // Reverse the order: access from end to start
        cs->b[i] = b[rev_index + 2];
    }
}
