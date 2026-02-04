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

extern Cluster *cluster;
extern Cluster *object;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Cluster *fast = object;
    Cluster *slow = object;

    if (object == (Cluster *)((void *)0)) return;

    while (1) {
        fast = fast->next;
        if (fast == (Cluster *)((void *)0)) break;
        fast = fast->next;
        if (fast == (Cluster *)((void *)0)) break;
        slow = slow->next;
    }

    cluster = slow;
    if (cluster->count < object->count)
        object = cluster;
}
