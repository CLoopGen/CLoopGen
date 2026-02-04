#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _ExtentPacket {
    double center;
    ssize_t index;
    ssize_t left;
    ssize_t right;
} ExtentPacket;

typedef struct _Cluster {
    struct _Cluster *next;
    ExtentPacket red;
    ExtentPacket green;
    ExtentPacket blue;
    ssize_t count;
    ssize_t id;
} Cluster;

Cluster *background;
Cluster *cluster;

#define CLUSTER_COUNT (1 << 20)

static Cluster cluster_array[CLUSTER_COUNT];

void init_vars() {
    for (int i = 0; i < CLUSTER_COUNT - 1; i++) {
        cluster_array[i].next = &cluster_array[i + 1];
        cluster_array[i].count = rand() % 1000;
        cluster_array[i].id = i;
        cluster_array[i].red.center = 0.1 * i;
        cluster_array[i].green.center = 0.2 * i;
        cluster_array[i].blue.center = 0.3 * i;
    }
    cluster_array[CLUSTER_COUNT - 1].next = (Cluster *)((void *)0);
    cluster_array[CLUSTER_COUNT - 1].count = rand() % 1000;
    cluster_array[CLUSTER_COUNT - 1].id = CLUSTER_COUNT - 1;
    cluster_array[CLUSTER_COUNT - 1].red.center = 0.1 * CLUSTER_COUNT;
    cluster_array[CLUSTER_COUNT - 1].green.center = 0.2 * CLUSTER_COUNT;
    cluster_array[CLUSTER_COUNT - 1].blue.center = 0.3 * CLUSTER_COUNT;

    background = &cluster_array[0];
    cluster = &cluster_array[0];
}