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

int killer_scores[300];
int killer_scores2[300];
int killer_scores3[300];
move_s dummy = {0, 0, 0, 0, 0, 0};
move_s killer1[300];
move_s killer2[300];
move_s killer3[300];
int i;

void init_vars() {
    for (int j = 0; j < 300; j++) {
        killer_scores[j] = 0;
        killer_scores2[j] = 0;
        killer_scores3[j] = 0;
        killer1[j] = dummy;
        killer2[j] = dummy;
        killer3[j] = dummy;
    }
}