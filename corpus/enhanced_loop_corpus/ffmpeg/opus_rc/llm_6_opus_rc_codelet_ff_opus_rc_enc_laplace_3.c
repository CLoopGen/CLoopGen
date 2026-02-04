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
    uint32_t temp_symbol = symbol;
    int temp_i = i;
    while (temp_i < val && temp_symbol) {
        low += (temp_symbol << 1) + 2;
        temp_symbol = (temp_symbol * decay) >> 14;
        temp_i++;
    }
    i = temp_i;
}
