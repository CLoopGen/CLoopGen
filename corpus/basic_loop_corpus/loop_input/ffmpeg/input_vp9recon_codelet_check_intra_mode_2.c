#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

uint8_t *a_data;
uint8_t **a;
int n;
int val;

void init_vars() {
    size_t total_size = 1 << 20; // 1MB of data
    a_data = (uint8_t *)calloc(total_size, sizeof(uint8_t));
    if (!a_data) {
        exit(1);
    }
    a = (uint8_t **)malloc(sizeof(uint8_t *));
    if (!a) {
        exit(1);
    }
    a[0] = a_data;
    n = 0;
    val = 0x1234;
}
// End of file