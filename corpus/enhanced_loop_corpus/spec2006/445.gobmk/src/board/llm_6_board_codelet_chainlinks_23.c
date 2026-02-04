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



void loop() {
    int temp_origin[160];
    for (k = 0; k < s->neighbors; k++) {
        temp_origin[k] = string[s->neighborlist[k]].origin;
    }
    for (k = 0; k < s->neighbors; k++) {
        adj[k] = temp_origin[k];
    }
}
