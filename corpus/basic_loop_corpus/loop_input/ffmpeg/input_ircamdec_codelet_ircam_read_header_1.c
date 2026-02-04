#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct endianess {
    uint32_t magic;
    int is_le;
};

struct endianess table[7];
uint32_t magic;
int le;
int i;

void init_vars() {
    const uint32_t magic_values[7] = {
        0x12345678,
        0xABCDEF01,
        0x23456789,
        0xBCDEF012,
        0x3456789A,
        0xCDEF0123,
        0x456789AB
    };

    for (int idx = 0; idx < 7; idx++) {
        table[idx].magic = magic_values[idx];
        table[idx].is_le = (idx % 2); 
    }

    magic = 0x3456789A; 
    le = 0;
    i = 0;
}