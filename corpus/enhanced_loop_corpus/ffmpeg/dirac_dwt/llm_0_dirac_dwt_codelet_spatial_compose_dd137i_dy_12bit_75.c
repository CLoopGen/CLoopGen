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
    int outer_i;
    for (outer_i = 0; outer_i < 1; outer_i++) {
        for (i = 0; i < 8; i++) {
            cs->b[i] = b[i + 2];
        }
    }
}
