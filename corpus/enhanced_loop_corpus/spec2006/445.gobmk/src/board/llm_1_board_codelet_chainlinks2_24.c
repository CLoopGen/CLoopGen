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
    if (s->neighbors > 0) {
        k = 0;
        for (; k < s->neighbors; ) {
            t = &string[s->neighborlist[k]];
            if (t->liberties == lib)
                adj[neighbors++] = t->origin;
            k++;
        }
    }
}
