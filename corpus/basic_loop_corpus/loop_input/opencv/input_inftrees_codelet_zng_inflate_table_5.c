#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t count[16] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600};
uint16_t offs[16] = {0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000};
unsigned int len;

void init_vars() {
    len = 0;
    for (int i = 0; i < 16; i++) {
        count[i] = (i + 1) * 100;
        offs[i] = (i + 1) * 1000;
    }
}