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



void loop(){
    int j, k;
    for (j = 0; j < 2; j++)
        for (k = 0; k < 3; k++) {
            i = j * 3 + k;
            cs->b[i] = b[i + 2];
        }
}
