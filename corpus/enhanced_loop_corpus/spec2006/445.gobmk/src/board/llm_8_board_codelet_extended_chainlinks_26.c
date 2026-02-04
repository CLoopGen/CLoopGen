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



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and doubled effective trip count via unrolling
    int i;
    for (i = 0; i < s->neighbors; i += 2) {
        int idx1 = s->neighborlist[i];
        adj[i] = string[idx1].origin;
        int mapped1 = string_number[adj[i]];
        string[mapped1].mark = string_mark;

        if (i + 1 < s->neighbors) {
            int idx2 = s->neighborlist[i + 1];
            adj[i + 1] = string[idx2].origin;
            int mapped2 = string_number[adj[i + 1]];
            string[mapped2].mark = string_mark;
        }
    }
}
