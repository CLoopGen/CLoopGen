#include <stdio.h>
#include <inttypes.h>

char input_data[131072]; // 128KB buffer to ensure ~0.01 sec runtime

char *c;
unsigned long ret;
long n;
unsigned long v;
int r;
long case_adjust;

void init_vars() {
    // Initialize scalar variables
    ret = 0x12345678UL;
    n = 0;
    v = 0;
    r = 0;
    case_adjust = 0x55555555L;
    
    // Initialize input data with printable characters and null terminator at end
    for (int i = 0; i < sizeof(input_data) - 1; i++) {
        input_data[i] = (char)(32 + (i % 95)); // ASCII 32-126 pattern
    }
    input_data[sizeof(input_data) - 1] = '\x00'; // Null terminator
    
    // Set pointer to beginning of data
    c = input_data;
}

// Define all extern variables at file scope
char *c = NULL;
unsigned long ret = 0;
long n = 0;
unsigned long v = 0;
int r = 0;
long case_adjust = 0;