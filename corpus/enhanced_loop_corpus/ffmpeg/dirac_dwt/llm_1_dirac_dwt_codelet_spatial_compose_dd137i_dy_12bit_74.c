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
    for (i = 0; i < 2; i++) {
        int offset = i * 4;
        int k;
        for (k = 0; k < 4 && (offset + k) < 8; k++)
            b[offset + k] = cs->b[offset + k];
    }
}
