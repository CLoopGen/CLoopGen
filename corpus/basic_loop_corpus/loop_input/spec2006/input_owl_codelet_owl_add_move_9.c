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

struct owl_move_data *moves;
int move;
int value;
char *reason;
int same_dragon;
int escape;
int defense_pos;
int k;

void init_vars() {
    // Allocate and initialize the moves array with 100,000 elements to ensure sufficient size
    // This size is chosen to allow k to start high enough for meaningful loop execution
    // while avoiding excessive memory use (approx 100k * 24 bytes ~ 2.4MB)
    const int num_moves = 100000;
    moves = calloc(num_moves, sizeof(struct owl_move_data));
    if (!moves) {
        exit(1);
    }

    // Initialize reason string
    reason = strdup("default_reason");
    if (!reason) {
        exit(1);
    }

    // Set default values for scalar variables
    move = 42;
    value = 100;
    same_dragon = 1;
    escape = 2;
    defense_pos = 3;

    // Initialize k to a safe starting index within bounds
    // We set k to min(50000, num_moves - 1) to ensure k-1 access is valid when k > 0
    k = 50000;
    if (k >= num_moves) {
        k = num_moves - 1;
    }

    // Pre-initialize moves[0..k] to avoid undefined behavior when copying
    for (int i = 0; i <= k; i++) {
        moves[i].pos = i * 10;
        moves[i].value = 200 + i;  // Ensure descending order so condition triggers
        // Cast away const for initialization only
        ((char**)&moves[i].name)[0] = reason;
        moves[i].same_dragon = 0;
        moves[i].escape = 0;
        moves[i].defense_pos = 0;
    }
}