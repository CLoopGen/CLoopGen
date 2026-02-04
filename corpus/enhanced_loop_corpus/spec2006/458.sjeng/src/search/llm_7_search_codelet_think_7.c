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
for (i = 0; i < 300; i++) {
    int temp_score = killer_scores[i];
    killer_scores3[i] = killer_scores2[i];
    killer_scores2[i] = temp_score;
    killer_scores[i] = 0;
    killer3[i] = killer2[i];
    killer2[i] = killer1[i];
    killer1[i] = dummy;
}
}
