#include <stdio.h>

#include <inttypes.h>

typedef struct ssl_st SSL;

struct ssl_id {
    SSL *s;
    uint64_t id;
    int status;
};


extern uint64_t id;
extern SSL *ssl;
extern int status;
extern struct ssl_id *ssl_ids;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 20 && ssl_ids[i].s != ((void *)0); i++);
    if (i < 20) {
        ssl_ids[i].s = ssl;
        ssl_ids[i].id = id;
        ssl_ids[i].status = status;
        return;
    }
}
