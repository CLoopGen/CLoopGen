#include <inttypes.h>

#define ARRAY_SIZE 256 * 1024 * 1024 / sizeof(unsigned short)

unsigned short equot[9] = {100, 200, 300, 400, 500, 600, 700, 800, 900};
unsigned short num[ARRAY_SIZE];
int i;

void init_vars() {
    for (int j = 0; j < 9; j++) {
        equot[j] = (j + 1) * 100;
    }
    for (int j = 0; j < ARRAY_SIZE; j++) {
        num[j] = 0;
    }
    i = 0;
}