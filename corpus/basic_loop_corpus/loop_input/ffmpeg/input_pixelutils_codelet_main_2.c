#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf2;
uint32_t state;
int k;

void init_vars() {
    size_t total_size = 640 * 480;
    buf2 = (uint8_t *)malloc(total_size * sizeof(uint8_t));
    if (!buf2) {
        exit(1);
    }
    state = 314159265; 
}

void loop(); 

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}