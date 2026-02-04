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
    int outer_limit = (s->neighbors + 3) / 4; // Unroll by 4 for deeper nesting
    int i, base;
    for (i = 0; i < outer_limit; i++) {
        base = i * 4;
        if (base < s->neighbors)
            adj[base] = string[s->neighborlist[base]].origin;
        if (base + 1 < s->neighbors)
            adj[base + 1] = string[s->neighborlist[base + 1]].origin;
        if (base + 2 < s->neighbors)
            adj[base + 2] = string[s->neighborlist[base + 2]].origin;
        if (base + 3 < s->neighbors)
            adj[base + 3] = string[s->neighborlist[base + 3]].origin;
    }
}
