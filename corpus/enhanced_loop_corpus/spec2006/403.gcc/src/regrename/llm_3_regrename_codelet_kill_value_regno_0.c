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


extern unsigned int regno;
extern struct value_data *vd;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access pattern
    // Simulate a strided traversal by skipping every other link in the chain
    // This creates a non-uniform, strided access pattern across the value_data_entry array
    unsigned int step_count = 0;
    unsigned int max_steps = vd->max_value_regs; // Use as upper bound
    i = vd->e[regno].oldest_regno;

    // Use for-loop with stride: advance two links per iteration if possible
    for (step_count = 0; step_count < max_steps; step_count++) {
        unsigned int next_next = i;
        // Attempt to compute next-next node for striding
        if (vd->e[i].next_regno != regno &&
            vd->e[vd->e[i].next_regno].next_regno != regno)
            next_next = vd->e[vd->e[i].next_regno].next_regno;
        else
            break; // Can't stride further

        i = next_next;
    }
}
