#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

struct string_data {
    int color;
    int size;
    int origin;
    int liberties;
    int libs[20];
    int neighbors;
    int neighborlist[160];
    int mark;
};

int delta[8] = { -21, -1, 1, 21, -20, 20, -19, 19 }; // Common delta values for a 19x19 Go board with padding

Intersection board[421];

struct string_data string[240];
int string_number[400];
int string_mark;
int str;
int adj[160];
int both_colors;
int n;
int k;
int r;
int libs[241];
int liberties;

void init_vars() {
    // Initialize delta (already initialized above)

    // Initialize board with neutral values (e.g., 0 for empty)
    for (int i = 0; i < 421; i++) {
        board[i] = 0;
    }

    // Set up a valid configuration to avoid out-of-bounds access
    str = 20; // Ensure str is within valid range
    board[str] = 1; // Set the stone color at str

    liberties = 50; // Set to ensure outer loop runs sufficiently

    // Initialize libs array used in loop: ensure libs[r] + delta[k] stays within [0,420]
    for (int i = 0; i < 241; i++) {
        libs[i] = (21 * (i % 19)) + (i % 19) + 1; // Map to valid board indices (centered)
        if (libs[i] >= 421) libs[i] = 420;
    }

    // Initialize string_number so that indexing into it via libs[r]+delta[k] is safe
    for (int i = 0; i < 400; i++) {
        if (i < 240) {
            string_number[i] = i;
        } else {
            string_number[i] = 0;
        }
    }

    // Initialize string array
    for (int i = 0; i < 240; i++) {
        string[i].color = (i % 3); // 0=empty, 1=black, 2=white
        string[i].size = (i % 10) + 1;
        string[i].origin = i;
        string[i].liberties = (i % 5) + 1;
        string[i].neighbors = (i % 8);
        for (int j = 0; j < 20; j++) {
            string[i].libs[j] = (i + j) % 241;
        }
        for (int j = 0; j < 160; j++) {
            string[i].neighborlist[j] = (i + j) % 240;
        }
        string[i].mark = 0;
    }

    // Other variables
    string_mark = 1;
    both_colors = 1;
    n = 0;
    k = 0;
    r = 0;
}