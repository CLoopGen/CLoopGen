#include <stdio.h>

#include <inttypes.h>

struct buf_mem_st {
    size_t length;
    char *data;
    size_t max;
    unsigned long flags;
};


typedef struct buf_mem_st BUF_MEM;

typedef struct wpacket_sub WPACKET_SUB;

struct wpacket_sub {
    WPACKET_SUB *parent;
    size_t packet_len;
    size_t lenbytes;
    size_t pwritten;
    unsigned int flags;
};


struct wpacket_st {
    BUF_MEM *buf;
    unsigned char *staticbuf;
    size_t curr;
    size_t written;
    size_t maxsize;
    WPACKET_SUB *subs;
    unsigned int endfirst : 1;
};


typedef struct wpacket_st WPACKET;

extern WPACKET *pkt;
extern WPACKET_SUB *sub;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access through an array-like traversal using an index and assumed linear layout (simulating heap-allocated pool of WPACKET_SUB elements)
    size_t idx = 0;
    WPACKET_SUB *base_ptr = pkt->subs;
    WPACKET_SUB *access_ptr = base_ptr;
    for (; access_ptr != ((void *)0) && access_ptr->parent != ((void *)0); idx += 2) { // strided index increment
        access_ptr = (WPACKET_SUB*)((char*)base_ptr + idx * sizeof(void*)); // indirect, indexed byte offset
        if (((WPACKET_SUB*)((char*)access_ptr))->parent == ((void *)0))
            break;
    }
}
