#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

struct connection_data *conn;
int pos;

void init_vars() {
    conn = (struct connection_data*)malloc(sizeof(struct connection_data));
    if (!conn) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    memset(conn->distances, 0, sizeof(conn->distances));
    memset(conn->deltas, 0, sizeof(conn->deltas));
    memset(conn->coming_from, 0, sizeof(conn->coming_from));
    memset(conn->vulnerable1, 0, sizeof(conn->vulnerable1));
    memset(conn->vulnerable2, 0, sizeof(conn->vulnerable2));
    memset(conn->queue, 0, sizeof(conn->queue));
    conn->queue_start = 0;
    conn->queue_end = 0;

    pos = 0;
}