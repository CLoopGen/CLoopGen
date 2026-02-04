#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

unsigned char *data;
int i;
unsigned long *p;
unsigned long ri;
unsigned char *d;
unsigned char *end;

static unsigned char data_buffer[1 << 20]; // 1MB buffer
static unsigned long p_buffer[18]; // Size to match loop: i < (16 + 2)

void init_vars() {
    data = data_buffer;
    p = p_buffer;
    d = data;
    end = data + sizeof(data_buffer);

    for (int i = 0; i < 18; i++) {
        p[i] = 0xdeadbeefUL + i;
    }

    for (size_t i = 0; i < sizeof(data_buffer); i++) {
        data[i] = (unsigned char)(i & 0xFF);
    }
}