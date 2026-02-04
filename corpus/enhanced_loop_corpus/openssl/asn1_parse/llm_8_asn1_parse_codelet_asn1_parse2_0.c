#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_OCTET_STRING;

extern  unsigned char *opp;
extern ASN1_OCTET_STRING *os;
extern int i;
extern int printable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = os->length;
    for (i = 0; i < limit; i += 2) {
        if (i + 1 >= os->length) {
            if (((opp[i] < ' ') && (opp[i] != '\n') && (opp[i] != '\r') && (opp[i] != '\t')) || (opp[i] > '~')) {
                printable = 0;
                break;
            }
        } else {
            unsigned char c1 = opp[i];
            unsigned char c2 = opp[i + 1];
            int cond1 = ((c1 < ' ') && (c1 != '\n') && (c1 != '\r') && (c1 != '\t')) || (c1 > '~');
            int cond2 = ((c2 < ' ') && (c2 != '\n') && (c2 != '\r') && (c2 != '\t')) || (c2 > '~');
            if (cond1 || cond2) {
                printable = 0;
                break;
            }
        }
    }
}
