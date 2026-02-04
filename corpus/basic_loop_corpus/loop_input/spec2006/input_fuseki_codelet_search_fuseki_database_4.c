#include <inttypes.h>

int fuseki_value[361];
int num_fuseki_moves;
int q;
int k;
int best_fuseki_value;

void init_vars() {
    num_fuseki_moves = 361;
    best_fuseki_value = 10000;
    q = 500000;

    for (int i = 0; i < num_fuseki_moves; i++) {
        fuseki_value[i] = best_fuseki_value / 2;
    }

    fuseki_value[num_fuseki_moves - 1] = best_fuseki_value / 10;
}