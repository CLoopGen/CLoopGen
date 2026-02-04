#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int score[8];
extern int i;
extern int best_fcode;
extern int best_score;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int updated;
for (i = 1; i < 8; i++) {
    updated = (score[i] > best_score);
    if (updated) {
        best_score = score[i];
        best_fcode = i;
    } else {
        continue;
    }
}
}
