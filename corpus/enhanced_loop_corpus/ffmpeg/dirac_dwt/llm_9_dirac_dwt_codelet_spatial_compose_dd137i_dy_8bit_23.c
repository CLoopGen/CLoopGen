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



void loop(){
    for (i = 0; i < 4; i++) {
        cs->b[i]     = b[i + 2];
        cs->b[i + 4] = b[i + 6];
        cs->b[i]     += 1;
        cs->b[i + 4] += 1;
    }
}
