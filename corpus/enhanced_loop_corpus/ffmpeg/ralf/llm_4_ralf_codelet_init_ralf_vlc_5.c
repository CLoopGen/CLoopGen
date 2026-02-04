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
    for (i = 0; i < elems; i++) {
        if (lens[i] < 18) {
            codes[i] = prefixes[lens[i]]++;
        }
    }
}
