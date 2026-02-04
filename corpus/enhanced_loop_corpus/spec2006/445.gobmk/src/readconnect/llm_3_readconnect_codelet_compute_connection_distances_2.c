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
    int stride = 2;
    int start = 19 + 2;
    int limit = (19 + 1) * (19 + 1);
    for (int idx = start; idx < limit; idx += stride) {
        conn->distances[idx] = 100000;
        conn->deltas[idx] = 0;
        conn->coming_from[idx] = 0;
        conn->vulnerable1[idx] = 0;
        conn->vulnerable2[idx] = 0;
    }
    // Handle odd indices if limit is not reached
    for (int idx = start + 1; idx < limit; idx += stride) {
        conn->distances[idx] = 100000;
        conn->deltas[idx] = 0;
        conn->coming_from[idx] = 0;
        conn->vulnerable1[idx] = 0;
        conn->vulnerable2[idx] = 0;
    }
}
