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
extern int lib;
extern struct string_data *s;
extern struct string_data *t;
extern int k;
extern int neighbors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < s->neighbors; i++) {
        for (int j = 0; j < 1; j++) {  // Artificially nested with depth 2, single iteration inner loop
            t = &string[s->neighborlist[i]];
            if (t->liberties <= lib)
                adj[neighbors++] = t->origin;
        }
    }
}
