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
    for (i = 0; i < 7 && le == 0; i++) {
        if (magic == table[i].magic) {
            le = table[i].is_le;
        }
    }
}
