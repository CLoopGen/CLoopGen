#include <stdio.h>

#include <inttypes.h>

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


extern struct string_data string[240];
extern int string_number[400];
extern int string_mark;
extern int adj[160];
extern struct string_data *s;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int i, j;
    for (i = 0, j = s->neighbors - 1; i < s->neighbors; i++, j--) {
        adj[i] = string[s->neighborlist[i]].origin;
        if (j != i) {
            adj[j] = string[s->neighborlist[j]].origin;
        }
        string[string_number[adj[i]]].mark = string_mark;
        if (j != i) {
            string[string_number[adj[j]]].mark = string_mark;
        }
    }
}
