#include <stdio.h>

#include <inttypes.h>

typedef struct ssl_st SSL;

struct ssl_id {
    SSL *s;
    uint64_t id;
    int status;
};


extern struct ssl_id *ssl_ids;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        ssl_ids[i].id = (18446744073709551615UL);
        ssl_ids[i + 5].id = (18446744073709551615UL);
        ssl_ids[i + 10].id = (18446744073709551615UL);
        ssl_ids[i + 15].id = (18446744073709551615UL);
    }
}
