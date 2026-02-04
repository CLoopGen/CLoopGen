#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *data;
int i;
unsigned int *p;
unsigned int ri;
unsigned char *d;
unsigned char *end;

#define DATA_SIZE (512 * 1024) // 512 KB data buffer
#define P_SIZE (16 + 2)

static unsigned char data_buffer[DATA_SIZE];
static unsigned int p_buffer[P_SIZE];

void init_vars() {
    // Initialize data and end pointers
    data = data_buffer;
    end = data + DATA_SIZE;
    
    // Initialize d to start of data
    d = data;
    
    // Initialize p array pointer
    p = p_buffer;
    
    // Initialize p with non-zero values to make XOR meaningful
    for (int j = 0; j < P_SIZE; j++) {
        p[j] = 0xDEADBEEF ^ (j << 2);
    }
    
    // Initialize data buffer with predictable pattern
    for (int j = 0; j < DATA_SIZE; j++) {
        data[j] = (unsigned char)(j & 0xFF);
    }
    
    // Initialize other scalar variables
    i = 0;
    ri = 0;
}