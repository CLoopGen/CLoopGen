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
    Cluster *traverse = background;
    Cluster *candidate = (Cluster *)((void *)0);

    for (; traverse != (Cluster *)((void *)0) && traverse->next != (Cluster *)((void *)0); traverse = traverse->next) {
        if (traverse->count > background->count) {
            candidate = traverse;
        }
        if (candidate != (Cluster *)((void *)0)) {
            background = candidate;
        }
    }
}
