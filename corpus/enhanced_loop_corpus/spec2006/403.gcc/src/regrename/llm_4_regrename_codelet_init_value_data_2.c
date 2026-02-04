#include <stdio.h>

#include <inttypes.h>

enum machine_mode {
    VOIDmode,
    BImode,
    QImode,
    HImode,
    SImode,
    DImode,
    TImode,
    OImode,
    PQImode,
    PHImode,
    PSImode,
    PDImode,
    QFmode,
    HFmode,
    TQFmode,
    SFmode,
    DFmode,
    XFmode,
    TFmode,
    QCmode,
    HCmode,
    SCmode,
    DCmode,
    XCmode,
    TCmode,
    CQImode,
    CHImode,
    CSImode,
    CDImode,
    CTImode,
    COImode,
    V2QImode,
    V2HImode,
    V2SImode,
    V2DImode,
    V4QImode,
    V4HImode,
    V4SImode,
    V4DImode,
    V8QImode,
    V8HImode,
    V8SImode,
    V8DImode,
    V16QImode,
    V2SFmode,
    V2DFmode,
    V4SFmode,
    V4DFmode,
    V8SFmode,
    V8DFmode,
    V16SFmode,
    BLKmode,
    CCmode,
    CCGCmode,
    CCGOCmode,
    CCNOmode,
    CCZmode,
    CCFPmode,
    CCFPUmode,
    MAX_MACHINE_MODE
};


struct value_data_entry {
    enum machine_mode mode;
    unsigned int oldest_regno;
    unsigned int next_regno;
};


struct value_data {
    struct value_data_entry e[53];
    unsigned int max_value_regs;
};


extern struct value_data *vd;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 53; ++i) {
        if (i % 2 == 0) {
            vd->e[i].mode = VOIDmode;
            vd->e[i].oldest_regno = i;
            vd->e[i].next_regno = (~(unsigned int)0);
        } else {
            continue;
        }
    }
}
