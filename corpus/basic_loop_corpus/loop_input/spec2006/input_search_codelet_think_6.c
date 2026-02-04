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

move_s pv[300][300];
move_s dummy;
int i;
int j;

void init_vars() {
    dummy.from = 0;
    dummy.target = 1;
    dummy.captured = 2;
    dummy.promoted = 3;
    dummy.castled = 4;
    dummy.ep = 5;
}