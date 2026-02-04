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

extern int killer_scores[300];
extern int killer_scores2[300];
extern int killer_scores3[300];
extern move_s dummy;
extern move_s killer1[300];
extern move_s killer2[300];
extern move_s killer3[300];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 100; i++) {
        killer_scores[i] = 0;
        killer_scores2[i] = 0;
        killer_scores3[i] = 0;
        killer1[i] = dummy;
        killer2[i] = dummy;
        killer3[i] = dummy;

        killer_scores[i + 100] = 0;
        killer_scores2[i + 100] = 0;
        killer_scores3[i + 100] = 0;
        killer1[i + 100] = dummy;
        killer2[i + 100] = dummy;
        killer3[i + 100] = dummy;

        killer_scores[i + 200] = 0;
        killer_scores2[i + 200] = 0;
        killer_scores3[i + 200] = 0;
        killer1[i + 200] = dummy;
        killer2[i + 200] = dummy;
        killer3[i + 200] = dummy;
    }
}
