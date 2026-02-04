#include <stdint.h>

int i;
int noperands = 30;
int first_inpaddr_num[30];
int first_outpaddr_num[30];

void init_vars() {
    noperands = 30;
    for (int j = 0; j < 30; j++) {
        first_inpaddr_num[j] = -2;
        first_outpaddr_num[j] = -2;
    }
}