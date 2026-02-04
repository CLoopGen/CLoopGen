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


extern int delta[8];
extern Intersection board[421];
extern struct string_data string[240];
extern int string_number[400];
extern int string_mark;
extern int str;
extern int adj[160];
extern int both_colors;
extern int n;
extern int k;
extern int r;
extern int libs[241];
extern int liberties;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity by flattening nested loops into a single loop with fixed unroll simulation.
    // Replaces inner loop with direct per-direction checks, reducing loop control overhead.
    // Also adds early termination if n exceeds a practical limit (e.g., 160) to avoid overflow.

    int max_n = 160;
    for (r = 0; r < liberties && n < max_n; r++) {
        int lib_pos = libs[r];

        // Unroll k = 0
        if ((board[lib_pos + delta[0]] == (1 + 2 - (board[str])) || 
             (both_colors && board[lib_pos + delta[0]] == board[str])) && 
            (string[string_number[lib_pos + delta[0]]].mark != string_mark)) {
            adj[n] = string[string_number[lib_pos + delta[0]]].origin;
            string[string_number[adj[n]]].mark = string_mark;
            n++;
        }
        if (n >= max_n) continue;

        // Unroll k = 1
        if ((board[lib_pos + delta[1]] == (1 + 2 - (board[str])) || 
             (both_colors && board[lib_pos + delta[1]] == board[str])) && 
            (string[string_number[lib_pos + delta[1]]].mark != string_mark)) {
            adj[n] = string[string_number[lib_pos + delta[1]]].origin;
            string[string_number[adj[n]]].mark = string_mark;
            n++;
        }
        if (n >= max_n) continue;

        // Unroll k = 2
        if ((board[lib_pos + delta[2]] == (1 + 2 - (board[str])) || 
             (both_colors && board[lib_pos + delta[2]] == board[str])) && 
            (string[string_number[lib_pos + delta[2]]].mark != string_mark)) {
            adj[n] = string[string_number[lib_pos + delta[2]]].origin;
            string[string_number[adj[n]]].mark = string_mark;
            n++;
        }
        if (n >= max_n) continue;

        // Unroll k = 3
        if ((board[lib_pos + delta[3]] == (1 + 2 - (board[str])) || 
             (both_colors && board[lib_pos + delta[3]] == board[str])) && 
            (string[string_number[lib_pos + delta[3]]].mark != string_mark)) {
            adj[n] = string[string_number[lib_pos + delta[3]]].origin;
            string[string_number[adj[n]]].mark = string_mark;
            n++;
        }
    }
}
