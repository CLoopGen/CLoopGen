#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Intersection;

struct eyevalue {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
};

struct eye_data {
    int color;
    int esize;
    int msize;
    int origin;
    struct eyevalue value;
    int attack_point;
    int defense_point;
    char marginal;
    char type;
    char neighbors;
    char marginal_neighbors;
    char cut;
};

struct half_eye_data {
    float value;
    char type;
    int num_attacks;
    int attack_point[4];
    int num_defends;
    int defense_point[4];
};

struct local_owl_data {
    char goal[400];
    char boundary[400];
    char escape_values[400];
    int color;
    struct eye_data my_eye[400];
    struct half_eye_data half_eye[400];
    int lunch[10];
    int lunch_attack_code[10];
    int lunch_attack_point[10];
    int lunch_defend_code[10];
    int lunch_defense_point[10];
    char inessential[400];
    int lunches_are_current;
    char safe_move_cache[400];
    int restore_from;
    int number_in_stack;
};

int delta[8] = {-21, -20, -19, -1, 1, 19, 20, 21};
int board_size = 19;
Intersection board[421];
struct local_owl_data *owl;
int color = 1;
struct eye_data *eye;
char mw[400];
char mz[400];
int m;
int n;
int k;
int eye_color = 1;

void init_vars() {
    // Set board size to 19x19 for standard Go board
    board_size = 19;
    
    // Allocate and initialize owl data
    owl = (struct local_owl_data*)calloc(1, sizeof(struct local_owl_data));
    if (!owl) exit(1);
    
    // Allocate and initialize eye array of size 400 to match the declared arrays
    eye = (struct eye_data*)calloc(400, sizeof(struct eye_data));
    if (!eye) exit(1);
    
    // Initialize board with neutral values (3 means empty in many Go engines)
    for (int i = 0; i < 421; i++) {
        board[i] = 3; // Empty
    }
    
    // Mark valid region on board and place some colored stones
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            int pos = (19 + 2) + i * (19 + 1) + j;
            // Place color=1 stones in roughly half the positions to trigger loop body
            if ((i + j) % 3 == 0) {
                board[pos] = color;
            }
        }
    }
    
    // Initialize eye array: set up origins and colors within bounds
    for (int i = 0; i < 400; i++) {
        eye[i].color = eye_color;
        eye[i].origin = (i < 300) ? (i % 100) + 1 : 0; // Ensure some non-zero origins
        eye[i].marginal = (i % 7 == 0) ? 1 : 0;
    }
    
    // Initialize owl->goal with some true values to trigger mw increment
    for (int i = 0; i < 400; i++) {
        owl->goal[i] = (i % 5 == 0) ? 1 : 0;
    }
    
    // Zero-initialize mw and mz
    memset(mw, 0, 400);
    memset(mz, 0, 400);
}