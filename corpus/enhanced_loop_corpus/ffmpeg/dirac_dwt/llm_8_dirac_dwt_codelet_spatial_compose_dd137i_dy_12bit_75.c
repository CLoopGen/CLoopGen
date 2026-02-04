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
    for (i = 0; i < 16; i += 2) {
        int idx = i >> 1;
        if (idx < 8) {
            cs->b[idx] = b[idx + 2];
        }
    }
}
