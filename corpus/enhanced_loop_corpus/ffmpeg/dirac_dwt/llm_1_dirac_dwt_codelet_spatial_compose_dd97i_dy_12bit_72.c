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
for (i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++)
        b[i * 3 + j] = cs->b[i * 3 + j];
}
