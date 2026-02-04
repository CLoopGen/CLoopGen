#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t symbol;
extern int decay;
extern uint32_t low;
extern int i;
extern int val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < val && symbol > 1; i++) {
    low += (symbol << 2) + 4;
    low += (symbol << 1);
    symbol = (symbol * decay * decay) >> 28;
    i++; 
}
}
