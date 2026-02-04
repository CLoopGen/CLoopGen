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
    int temp_n = n; // Introduce local copy to eliminate WAW dependence on shared 'n'
    for (r = 0; r < liberties; r++) {
        for (k = 0; k < 4; k++) {
            Intersection neighbor_pos = libs[r] + delta[k];
            if ((board[neighbor_pos] == (1 + 2 - board[str]) || 
                 (both_colors && board[neighbor_pos] == board[str])) && 
                (string[string_number[neighbor_pos]].mark != string_mark)) {
                
                int str_num = string_number[neighbor_pos];
                adj[temp_n] = string[str_num].origin;
                string[string_number[adj[temp_n]]].mark = string_mark;
                temp_n++;
            }
        }
    }
    n = temp_n; // Single write to global 'n' after loop (eliminates loop-carried WAW)
}
