#include <stdio.h>
#include <inttypes.h>

int transformation[1369][8];
const int transformation2[8][2][2] = {
    {{1, 0}, {0, 1}},
    {{0, 1}, {-1, 0}},
    {{-1, 0}, {0, -1}},
    {{0, -1}, {1, 0}},
    {{1, 1}, {0, 1}},
    {{1, -1}, {1, 0}},
    {{-1, -1}, {0, -1}},
    {{-1, 1}, {-1, 0}}
};
int k;
int dx;
int dy;

void init_vars() {
    for (int i = 0; i < 1369; i++) {
        for (int j = 0; j < 8; j++) {
            transformation[i][j] = 0;
        }
    }
    k = 0;
    dx = 0;
    dy = 0;
}