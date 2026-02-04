#include <stdio.h>

#include <inttypes.h>

struct reading_cache {
    int boardsize;
    char board[400];
    int movenum;
    int nodes;
    int score;
    int remaining_depth;
    int routine;
    int str;
    int result;
    int move;
    int stack[5];
    int move_color[5];
};


extern struct reading_cache persistent_reading_cache[100];
extern int persistent_reading_cache_size;
extern int k;
extern int worst_entry;
extern int worst_score;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int candidate_entry = worst_entry;
    int candidate_score = worst_score;

    for (k = 1; k < persistent_reading_cache_size; k += 2) {
        int score_k = persistent_reading_cache[k].score;
        if (score_k < candidate_score) {
            candidate_score = score_k;
            candidate_entry = k;
        }

        if (k + 1 < persistent_reading_cache_size) {
            int next_score = persistent_reading_cache[k + 1].score;
            if (next_score < candidate_score) {
                candidate_score = next_score;
                candidate_entry = k + 1;
            }
        }
    }

    worst_score = candidate_score;
    worst_entry = candidate_entry;
}
