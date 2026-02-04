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
    int base = 19 + 2;
    int limit = (19 + 1) * (19 + 1);
    for (int i = 0; i < limit - base; i++) {
        int pos = base + i;
        conn->distances[pos] = 100000;
        conn->deltas[pos] = 0;
        conn->coming_from[pos] = 0;
        conn->vulnerable1[pos] = 0;
        conn->vulnerable2[pos] = 0;
    }
}
