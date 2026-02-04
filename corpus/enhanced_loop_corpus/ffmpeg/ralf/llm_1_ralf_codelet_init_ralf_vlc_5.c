#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int elems;
extern uint8_t lens[644];
extern uint16_t codes[644];
extern int prefixes[18];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (elems > 0) {
        i = 0;
        for (int outer = 0; outer < 1; outer++) {
            for (; i < elems; i++) {
                codes[i] = prefixes[lens[i]]++;
            }
        }
    }
}
