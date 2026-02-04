#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmin = 0;
int nmax = 13421772; // Approximately 64 MB of double data (13421772 * 8 bytes) for ~0.01 sec on modern CPU
double result_array[13421773]; // Size to cover nmax - nmin + 1 = 13421773 elements
int ii;

void init_vars() {
    nmin = 0;
    nmax = 13421772;
    for (int i = 0; i < 13421773; i++) {
        result_array[i] = 0.0;
    }
    ii = 0;
}