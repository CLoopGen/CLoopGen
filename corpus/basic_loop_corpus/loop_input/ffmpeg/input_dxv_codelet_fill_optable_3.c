#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct OpcodeTable {
    int16_t next;
    uint8_t val1;
    uint8_t val2;
} OpcodeTable;

OpcodeTable *table1;
unsigned int table2[256];
unsigned int x;
int i;
int j;
int k;

void init_vars() {
    // Allocate 1KB of OpcodeTable entries (512 entries)
    table1 = (OpcodeTable*)calloc(1024, sizeof(OpcodeTable));
    
    // Initialize table2 with descending values to ensure inner loop exits quickly
    for (int idx = 0; idx < 256; idx++) {
        table2[idx] = 255 - idx;
    }
    
    // Initialize scalar variables to valid values
    x = 512;  // within [0,1023] after masking
    j = 0;
    k = 0;
    
    // Ensure initial state leads to valid memory access
    for (int idx = 0; idx < 1024; idx++) {
        table1[idx].next = 0;
        table1[idx].val1 = 0;
        table1[idx].val2 = 0;
    }
}