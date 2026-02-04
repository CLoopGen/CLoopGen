#include <stdint.h>
#include <string.h>

unsigned short *a;
unsigned short *b;
int i;

static unsigned short a_data[134217728]; // ~256MB of data (134217728 elements * 2 bytes)
static unsigned short b_data[134217728]; // ~256MB of data

void init_vars() {
    a = a_data;
    b = b_data;
    i = 0;
    memset(a_data, 0x55, sizeof(a_data)); // Initialize with non-zero pattern
    memset(b_data, 0x00, sizeof(b_data)); // Clear destination
}