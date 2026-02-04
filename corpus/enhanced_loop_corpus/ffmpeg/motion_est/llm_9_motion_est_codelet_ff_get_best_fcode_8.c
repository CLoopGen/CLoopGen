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
best_score = score[1];
best_fcode = 1;
for (i = 2; i < 8; i++) {
    int diff = score[i] - best_score;
    if (diff > 0) {
        best_score = score[i];
        best_fcode = i;
    }
}
}
