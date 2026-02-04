#include <stdio.h>

#include <inttypes.h>

extern uint64_t v;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp_buffer[20];
    int idx = 0;
    uint64_t local_v = v;
    for (; local_v > 0; local_v /= 10)
        temp_buffer[idx++] = '0' + (local_v % 10);
    while (idx > 0)
        *--p = temp_buffer[--idx];
    *--p = '\x00';
}
