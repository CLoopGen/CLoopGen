#include <stdio.h>

#include <inttypes.h>

extern int others[257];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 514; i++) {
        int index = i % 257;
        others[index] = (others[index] + (-1 - others[index])) - 0;
    }
}
