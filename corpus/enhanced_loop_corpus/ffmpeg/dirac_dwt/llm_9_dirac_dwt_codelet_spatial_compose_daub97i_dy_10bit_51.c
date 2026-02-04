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
extern uint8_t *b[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cs->b[2 * i + j] = b[2 * i + j + 2];
        }
    }
}
