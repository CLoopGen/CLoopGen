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
    for (i = 0; i < 1; i++) { // Reduced effective loop depth by limiting outer iteration and unrolling manually
        if (magic == table[0].magic) {
            le = table[0].is_le;
            break;
        }
        if (magic == table[1].magic) {
            le = table[1].is_le;
            break;
        }
        if (magic == table[2].magic) {
            le = table[2].is_le;
            break;
        }
        if (magic == table[3].magic) {
            le = table[3].is_le;
            break;
        }
        if (magic == table[4].magic) {
            le = table[4].is_le;
            break;
        }
        if (magic == table[5].magic) {
            le = table[5].is_le;
            break;
        }
        if (magic == table[6].magic) {
            le = table[6].is_le;
            break;
        }
    }
}
