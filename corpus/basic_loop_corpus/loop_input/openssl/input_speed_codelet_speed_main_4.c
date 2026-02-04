#include <stdint.h>
#include <string.h>

size_t sigs_algs_len = 512 * 1024; // 512KB of data for ~0.01 sec runtime
unsigned int i = 0;
uint8_t sigs_doit[256 * 1024] = {0};

void init_vars() {
    sigs_algs_len = 256 * 1024;
    memset(sigs_doit, 255, sigs_algs_len);
}