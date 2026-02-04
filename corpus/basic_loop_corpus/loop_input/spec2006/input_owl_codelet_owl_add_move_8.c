#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct owl_move_data {
    int pos;
    int value;
    const char *name;
    int same_dragon;
    int escape;
    int defense_pos;
};

static struct owl_move_data moves_data[256 * 1024]; // ~256KB of data
struct owl_move_data *moves = moves_data;
int move;
int same_dragon;
int escape;
int k;

void init_vars() {
    // Initialize each element of moves_data
    for (int i = 0; i < 256 * 1024; i++) {
        moves_data[i].pos = (i % 1000) + 1;
        moves_data[i].value = (i < 1000) ? i - 500 : -1; // Ensure some values are -1 after a point
        // Use malloc and strcpy to allow valid const char* initialization
        char *temp_str = malloc(16);
        snprintf(temp_str, 16, "move_%d", i);
        moves_data[i].name = temp_str;
        moves_data[i].same_dragon = i % 100;
        moves_data[i].escape = (i % 3) != 0;
        moves_data[i].defense_pos = i * 2;
    }

    // Initialize scalar variables
    move = 500;
    same_dragon = 75;
    escape = 1;
    k = 0;
}