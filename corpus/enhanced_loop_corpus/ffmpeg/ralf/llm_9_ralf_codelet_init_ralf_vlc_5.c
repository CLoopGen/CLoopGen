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
        uint8_t len = lens[i];
        codes[i] = prefixes[len] + i;
        prefixes[len] += 2;
    }
}
