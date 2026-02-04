#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_BIT_STRING;

extern ASN1_BIT_STRING *a;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_len = len;
    for (; temp_len > 0; temp_len--) {
        if (a->data[temp_len - 1]) {
            len = temp_len - 1;
            break;
        }
    }
}
