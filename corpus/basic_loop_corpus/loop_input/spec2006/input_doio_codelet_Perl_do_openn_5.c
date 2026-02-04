#include <stdio.h>
#include <inttypes.h>

char *type;
char data[1 << 24]; // 16MB to ensure ~0.01s runtime

void init_vars() {
    for (int i = 0; i < sizeof(data) - 256; i++) {
        data[i] = ' ';
    }
    for (int i = sizeof(data) - 256; i < sizeof(data) - 1; i++) {
        data[i] = 'a';
    }
    data[sizeof(data) - 1] = '\0';
    type = data;
}