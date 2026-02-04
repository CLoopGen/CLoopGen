#include <stdint.h>

int y;
int result;
int tmp_res[6];
int COEF[6];

void init_vars() {
    for (int i = 0; i < 6; i++) {
        tmp_res[i] = i + 1;
        COEF[i] = (i * 2) + 1;
    }
    y = 0;
    result = 0;
}