#include <stdio.h>
#include <inttypes.h>

unsigned char *p;
char *ret;
int i;
char *f;

static unsigned char p_data[1024 * 128];    // 128KB of input data
static char ret_data[1024 * 128 * 2];      // Each byte in p produces two bytes in ret
static char f_data[16] = "0123456789ABCDEF"; // Mapping for hex digits

void init_vars() {
    p = p_data;
    ret = ret_data;
    f = f_data;

    // Initialize p_data with sample values to ensure defined behavior
    for (int j = 0; j < sizeof(p_data); j++) {
        p_data[j] = (unsigned char)(j & 0xFF);
    }

    // Initialize ret_data to zero to avoid garbage
    for (int j = 0; j < sizeof(ret_data); j++) {
        ret_data[j] = 0;
    }
}