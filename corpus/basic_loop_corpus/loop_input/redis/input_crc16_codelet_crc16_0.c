#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t crc16tab[256];
char *buf;
int len;
int counter;
uint16_t crc;

void init_vars() {
    len = 16777216; // 16MB data size for ~0.01 sec runtime on modern CPU
    buf = malloc(len);
    if (!buf) {
        exit(1);
    }
    for (int i = 0; i < len; i++) {
        buf[i] = rand() & 0xFF;
    }
    for (int i = 0; i < 256; i++) {
        uint16_t r = i;
        for (int j = 0; j < 8; j++) {
            if (r & 0x8000)
                r = (r << 1) ^ 0x1021;
            else
                r <<= 1;
        }
        crc16tab[i] = r;
    }
    crc = 0xFFFF;
    counter = 0;
}