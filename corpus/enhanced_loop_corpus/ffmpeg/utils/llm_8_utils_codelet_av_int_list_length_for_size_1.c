#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint16_t t;
extern uint16_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    uint16_t temp;
    for (; i < 65535 && (temp = l[i], temp != t); i += 2) {
        if ((i + 1) < 65535 && l[i + 1] == t) {
            i++;
            break;
        }
    }
}
