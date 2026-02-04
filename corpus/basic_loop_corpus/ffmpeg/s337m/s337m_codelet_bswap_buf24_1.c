#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < size / 3; i++ , data += 3)
    do {
        uint8_t SWAP_tmp = data[2];
        data[2] = data[0];
        data[0] = SWAP_tmp;
    } while (0);

}
