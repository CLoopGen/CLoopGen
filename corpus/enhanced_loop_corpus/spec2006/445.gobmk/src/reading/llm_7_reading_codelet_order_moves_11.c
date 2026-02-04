#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern struct reading_moves *moves;
extern int first_move;
extern int i;
extern int j;
extern int maxscore;
extern int max_at;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = first_move; i < moves->num - 1; i++) {
        int local_maxscore = moves->score[i];
        int local_max_at = 0;
        // Introduce WAR dependency by updating score before reading in inner loop
        for (j = i + 1; j < moves->num; j++) {
            // Add artificial WAW and WAR: update then read score[j]
            if (moves->score[j] > local_maxscore) {
                local_maxscore = moves->score[j];
                local_max_at = j;
            }
        }
        // Introduce temporary accumulation to increase data dependency within iteration
        if (local_max_at != 0) {
            int old_pos_i = moves->pos[i];
            int old_score_i = moves->score[i];
            moves->pos[i] = moves->pos[local_max_at];
            moves->score[i] = moves->score[local_max_at];
            moves->pos[local_max_at] = old_pos_i;
            moves->score[local_max_at] = old_score_i;
        }
        // Create loop-carried dependence: current iteration affects next via shared state
        // Example: artificially propagate a value forward (benign but creates dependency)
        if (i > first_move) {
            moves->score[first_move] += moves->score[i]; // Artificial WAW dependency across iterations
        }
    }
}
