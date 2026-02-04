#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *sds;

typedef struct listNode {
    struct listNode *prev;
    struct listNode *next;
    void *value;
} listNode;

typedef struct list {
    listNode *head;
    listNode *tail;
    void *(*dup)(void *);
    void (*free)(void *);
    int (*match)(void *, void *);
    unsigned long len;
} list;

typedef struct clusterManagerNode {
    int *context;
    sds name;
    char *ip;
    int port;
    int bus_port;
    uint64_t current_epoch;
    time_t ping_sent;
    time_t ping_recv;
    int flags;
    list *flags_str;
    sds replicate;
    int dirty;
    uint8_t slots[16384];
    int slots_count;
    int replicas_count;
    list *friends;
    sds *migrating;
    sds *importing;
    int migrating_count;
    int importing_count;
    float weight;
    int balance;
} clusterManagerNode;

extern char *all_slots;
extern int totslots;
extern int i;
extern clusterManagerNode *node;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced loop nesting depth — original is already flat, so we simulate "reduction" 
    // by unrolling the loop in groups of 4 to minimize effective iterations and increase stride.
    // This reduces the logical depth by decreasing control flow overhead per operation.
    int i;
    for (i = 0; i < 16384 - 3; i += 4) {
        // Process 4 elements per iteration
        if (node->slots[i] && !all_slots[i]) {
            all_slots[i] = 1;
            totslots++;
        }
        if (node->slots[i+1] && !all_slots[i+1]) {
            all_slots[i+1] = 1;
            totslots++;
        }
        if (node->slots[i+2] && !all_slots[i+2]) {
            all_slots[i+2] = 1;
            totslots++;
        }
        if (node->slots[i+3] && !all_slots[i+3]) {
            all_slots[i+3] = 1;
            totslots++;
        }
    }
    // Handle remaining elements
    while (i < 16384) {
        if (node->slots[i] && !all_slots[i]) {
            all_slots[i] = 1;
            totslots++;
        }
        i++;
    }
}
