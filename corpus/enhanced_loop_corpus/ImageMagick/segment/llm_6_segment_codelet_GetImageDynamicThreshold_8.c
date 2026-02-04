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

extern Cluster *background;
extern Cluster *cluster;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Cluster *current = background;
    Cluster *max_cluster = background;
    ssize_t max_count = background->count;

    for (; current->next != (Cluster *)((void *)0); current = current->next) {
        if (current->count > max_count) {
            max_count = current->count;
            max_cluster = current;
        }
    }
    background = max_cluster;
}
