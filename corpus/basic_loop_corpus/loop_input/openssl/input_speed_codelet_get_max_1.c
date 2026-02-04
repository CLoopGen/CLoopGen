#include <inttypes.h>
#include <string.h>

#define DATA_SIZE (512 * 1024)

uint8_t doit[DATA_SIZE];
size_t algs_len = DATA_SIZE;
size_t i = 0;
int maxcnt = 0;

void init_vars() {
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        doit[idx] = (uint8_t)(idx % 256);
    }
    algs_len = DATA_SIZE;
    i = 0;
    maxcnt = 0;
}