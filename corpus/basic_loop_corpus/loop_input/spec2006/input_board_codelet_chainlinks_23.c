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

struct string_data string[240];
int adj[160];
struct string_data *s;
int k;

void init_vars() {
    s = &string[100];
    s->neighbors = 160;
    for (int i = 0; i < 240; i++) {
        string[i].origin = i * 37; // arbitrary deterministic value
    }
    for (int i = 0; i < 160; i++) {
        s->neighborlist[i] = (i * 241) % 240; // ensure valid index into string[240]
    }
}