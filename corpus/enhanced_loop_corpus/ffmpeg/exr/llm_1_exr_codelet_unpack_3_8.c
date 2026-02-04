#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t s[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 4; i++) {
        for (int j = 1; j <= 4; j++) {
            int idx = (i - 1) * 4 + j;
            if (idx < 16)
                s[idx] = s[0];
        }
    }
}
