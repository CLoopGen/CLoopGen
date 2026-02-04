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
    uint8_t *temp[4];
    for (i = 0; i < 4; i++)
        temp[i] = b[i + 2];
    for (i = 0; i < 4; i++)
        cs->b[i] = temp[i];
}
