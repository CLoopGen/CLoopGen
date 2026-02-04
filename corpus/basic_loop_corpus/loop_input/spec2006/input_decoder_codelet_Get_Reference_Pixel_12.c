#include <inttypes.h>

int x;
int result;
int tmp_res[6];
int COEF[6];

void init_vars() {
    x = 0;
    result = 0;

    for (int i = 0; i < 6; i++) {
        tmp_res[i] = i + 1;
        COEF[i] = (i * 2) + 1;
    }
}