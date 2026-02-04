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
    int i, j;
    for (i = 21; i < 400; i++) {
        for (j = 0; j < 1; j++) { // Artificially nested with depth 2
            conn->distances[i] = 100000;
            conn->deltas[i] = 0;
            conn->coming_from[i] = 0;
            conn->vulnerable1[i] = 0;
            conn->vulnerable2[i] = 0;
        }
    }
}
