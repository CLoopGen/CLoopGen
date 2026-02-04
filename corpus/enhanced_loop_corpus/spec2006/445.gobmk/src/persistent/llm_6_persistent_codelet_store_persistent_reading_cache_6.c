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
    int temp_score;
    int temp_entry = worst_entry;
    int local_worst_score = worst_score;

    for (k = 1; k < persistent_reading_cache_size; k++) {
        temp_score = persistent_reading_cache[k].score;
        if (temp_score < local_worst_score) {
            local_worst_score = temp_score;
            temp_entry = k;
        }
    }

    worst_score = local_worst_score;
    worst_entry = temp_entry;
}
