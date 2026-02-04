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
extern int adj[160];
extern struct string_data *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (k = 0; k < s->neighbors && k < 160; k += 2) {
        if (s->neighborlist[k] >= 0 && s->neighborlist[k] < 240)
            adj[k] = string[s->neighborlist[k]].origin;
        if (k + 1 < s->neighbors && s->neighborlist[k+1] >= 0 && s->neighborlist[k+1] < 240)
            adj[k+1] = string[s->neighborlist[k+1]].origin;
    }
    // Fill remaining adj entries if neighbors is odd
    for (i = k; i < s->neighbors; i++)
        adj[i] = string[s->neighborlist[i]].origin;
}
