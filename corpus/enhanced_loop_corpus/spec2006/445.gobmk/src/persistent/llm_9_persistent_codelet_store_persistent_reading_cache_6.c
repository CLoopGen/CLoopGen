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
    worst_score = persistent_reading_cache[1].score;
    worst_entry = 1;
    for (k = 2; k < persistent_reading_cache_size; k += 2) {
        if (k + 1 < persistent_reading_cache_size) {
            int score1 = persistent_reading_cache[k].score;
            int score2 = persistent_reading_cache[k + 1].score;
            if (score1 < score2 && score1 < worst_score) {
                worst_score = score1;
                worst_entry = k;
            } else if (score2 < worst_score) {
                worst_score = score2;
                worst_entry = k + 1;
            }
        } else if (persistent_reading_cache[k].score < worst_score) {
            worst_score = persistent_reading_cache[k].score;
            worst_entry = k;
        }
    }
}
