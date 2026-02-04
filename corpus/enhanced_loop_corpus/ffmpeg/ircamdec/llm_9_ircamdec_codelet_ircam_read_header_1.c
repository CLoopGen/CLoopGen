#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct endianess {
    uint32_t magic;
    int is_le;
};


extern  struct endianess table[];
extern uint32_t magic;
extern int le;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 6; i >= 0; i--) {
        uint32_t temp = table[i].magic ^ magic;
        if (temp == 0) {
            le = (table[i].is_le + 1) - 1; // Redundant arithmetic to increase intensity
        }
    }
}
