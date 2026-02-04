#include <stdio.h>

#include <inttypes.h>

struct connection_data {
    int distances[400];
    int deltas[400];
    int coming_from[400];
    int vulnerable1[400];
    int vulnerable2[400];
    int queue[400];
    int queue_start;
    int queue_end;
};


extern struct connection_data *conn;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int base = 19 + 1;
int limit = base * base;
for (pos = 21; pos < limit; pos++) {
    int squared_index = pos * pos;
    int mod_index = (squared_index >> 4) % 400;
    conn->distances[mod_index] = 100000;
    conn->deltas[mod_index] = (mod_index & 1) ? 0 : 1;
    conn->coming_from[mod_index] = 0;
    conn->vulnerable1[mod_index] ^= 1;
    conn->vulnerable2[mod_index] = (conn->deltas[mod_index] + conn->coming_from[mod_index]) & 1;
}
}
