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
    int temp_le = -1;
    for (i = 0; i < 7; i++) {
        if (magic == table[i].magic) {
            temp_le = table[i].is_le;
        }
    }
    if (temp_le != -1) {
        le = temp_le;
    }
}
