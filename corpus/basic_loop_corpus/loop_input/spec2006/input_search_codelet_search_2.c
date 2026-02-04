#include <stdio.h>
#include <inttypes.h>

typedef struct {
    int from;
    int target;
    int captured;
    int promoted;
    int castled;
    int ep;
} move_s;

int ply = 100;
int pv_length[300];
move_s pv[300][300];
int j;

void init_vars() {
    for (int i = 0; i < 300; i++) {
        pv_length[i] = 0;
    }
    pv_length[ply + 1] = 200;

    for (int i = 0; i < 300; i++) {
        for (int j = 0; j < 300; j++) {
            pv[i][j].from = i ^ j;
            pv[i][j].target = i + j;
            pv[i][j].captured = (i * j) % 7;
            pv[i][j].promoted = (i + 2 * j) % 5;
            pv[i][j].castled = (i - j) & 1;
            pv[i][j].ep = (j * 3) % 11;
        }
    }
}