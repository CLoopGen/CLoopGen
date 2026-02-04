#include <stdio.h>
#include <inttypes.h>

const int transformation2[8][2][2] = {
    {{1, 0}, {0, 1}},
    {{1, 1}, {-1, 1}},
    {{1, -1}, {1, 1}},
    {{2, 1}, {1, 2}},
    {{2, -1}, {1, 2}},
    {{1, 2}, {-2, 1}},
    {{1, -2}, {2, 1}},
    {{3, 1}, {1, 3}}
};

int order[1764][8];

int i;
int j;
int i0;
int _usr_j0;
int k;
int ll;

void init_vars() {
    for (int idx = 0; idx < 1764; idx++) {
        order[idx][0] = idx;
        for (int ll = 1; ll < 8; ll++) {
            order[idx][ll] = 0;
        }
    }
    i = 0;
    j = 0;
    i0 = 0;
    _usr_j0 = 0;
    k = 0;
    ll = 0;
}