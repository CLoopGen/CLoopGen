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
extern uint8_t *b[8];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int indices[6] = {5, 4, 3, 2, 1, 0};
    for (i = 0; i < 6; i++) {
        int idx = indices[i];
        cs->b[idx] = b[idx + 2];
    }
}
