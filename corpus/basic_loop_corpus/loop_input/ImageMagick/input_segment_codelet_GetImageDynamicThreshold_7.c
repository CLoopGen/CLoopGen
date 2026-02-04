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

Cluster *cluster;
Cluster *object;

static Cluster* cluster_array = NULL;
static size_t num_clusters = 1000000; // Adjust to get ~0.01s runtime

void init_vars() {
    cluster_array = (Cluster*)calloc(num_clusters, sizeof(Cluster));
    if (!cluster_array) exit(1);

    for (size_t i = 0; i < num_clusters - 1; i++) {
        cluster_array[i].next = &cluster_array[i + 1];
        cluster_array[i].count = rand() % 1000;
        cluster_array[i].id = i;
    }
    cluster_array[num_clusters - 1].next = (Cluster*)((void*)0);
    cluster_array[num_clusters - 1].count = rand() % 1000;
    cluster_array[num_clusters - 1].id = num_clusters - 1;

    object = &cluster_array[0];
    cluster = &cluster_array[0];
}