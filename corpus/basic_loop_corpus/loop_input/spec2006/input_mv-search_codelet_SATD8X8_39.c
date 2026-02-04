#include <inttypes.h>

int i;
int m1[8][8];
int m2[8][8];
int m3[8][8];

void init_vars() {
    for (int j = 0; j < 8; j++) {
        for (int k = 0; k < 8; k++) {
            m1[j][k] = (j * 8 + k) % 100 + 1;
            m2[j][k] = (j * 8 + k) % 100 + 5;
            m3[j][k] = 0;
        }
    }
    i = 0;
}