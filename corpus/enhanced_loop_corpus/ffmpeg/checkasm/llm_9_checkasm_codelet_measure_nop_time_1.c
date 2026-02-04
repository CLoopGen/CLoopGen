#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t nops[10000];
extern int i;
extern uint64_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint64_t sum = 0;
for (i = 0; i < 5000; i++) {
    sum += t * i;
    nops[i] = sum & 0xFFFF;
    nops[9999 - i] = (sum >> 8) & 0xFFFF;
}
t = sum;
}
