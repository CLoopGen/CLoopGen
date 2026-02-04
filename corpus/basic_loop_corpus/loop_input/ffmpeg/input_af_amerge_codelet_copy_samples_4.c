#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct amerge_input {
    int nb_ch;
};

int nb_inputs = 131072; // Approximately 0.5 MB of data (131072 * sizeof(struct amerge_input) ≈ 512 KB)
struct amerge_input in[131072];
int i = 0;
int nb_ch = 0;

void init_vars() {
    for (int idx = 0; idx < nb_inputs; idx++) {
        in[idx].nb_ch = rand() % 10 + 1;
    }
}