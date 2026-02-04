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
        for (int k = 0; k < 300; k++) {
            pv[i][k].from = i ^ k;
            pv[i][k].target = i + k;
            pv[i][k].captured = (i * k) % 7;
            pv[i][k].promoted = (i + k * 2) % 5;
            pv[i][k].castled = (i - k) % 3;
            pv[i][k].ep = (i * 3 + k) % 11;
        }
    }
}