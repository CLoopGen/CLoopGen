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
for (r = 0; r < liberties; r++) {
    k = 0;
    if ((board[libs[r] + delta[k]] == (1 + 2 - (board[str])) || (both_colors && board[libs[r] + delta[k]] == board[str])) && (string[string_number[libs[r] + delta[k]]].mark != string_mark)) {
        adj[n] = string[string_number[libs[r] + delta[k]]].origin;
        string[string_number[adj[n]]].mark = string_mark;
        n++;
    }
    k = 1;
    if ((board[libs[r] + delta[k]] == (1 + 2 - (board[str])) || (both_colors && board[libs[r] + delta[k]] == board[str])) && (string[string_number[libs[r] + delta[k]]].mark != string_mark)) {
        adj[n] = string[string_number[libs[r] + delta[k]]].origin;
        string[string_number[adj[n]]].mark = string_mark;
        n++;
    }
    k = 2;
    if ((board[libs[r] + delta[k]] == (1 + 2 - (board[str])) || (both_colors && board[libs[r] + delta[k]] == board[str])) && (string[string_number[libs[r] + delta[k]]].mark != string_mark)) {
        adj[n] = string[string_number[libs[r] + delta[k]]].origin;
        string[string_number[adj[n]]].mark = string_mark;
        n++;
    }
    k = 3;
    if ((board[libs[r] + delta[k]] == (1 + 2 - (board[str])) || (both_colors && board[libs[r] + delta[k]] == board[str])) && (string[string_number[libs[r] + delta[k]]].mark != string_mark)) {
        adj[n] = string[string_number[libs[r] + delta[k]]].origin;
        string[string_number[adj[n]]].mark = string_mark;
        n++;
    }
}
}
