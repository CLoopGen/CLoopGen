#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *data;
uint64_t value;
size_t len;

static unsigned char data_buffer[1024 * 128]; // 128KB buffer

void init_vars() {
    // Initialize value with a non-zero pattern
    value = 0xA5F3E2D1C4B6987ULL;
    
    // Set length to full buffer size
    len = sizeof(data_buffer);
    
    // Initialize data pointer to the start of the buffer
    data = data_buffer;
    
    // Ensure the loop invariant: data will be advanced to end in loop
    // so we leave data pointing to beginning here, and loop will adjust
}