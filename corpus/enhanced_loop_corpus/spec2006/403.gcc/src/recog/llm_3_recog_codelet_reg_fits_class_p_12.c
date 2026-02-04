#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

enum mode_class {
    MODE_RANDOM,
    MODE_INT,
    MODE_FLOAT,
    MODE_PARTIAL_INT,
    MODE_CC,
    MODE_COMPLEX_INT,
    MODE_COMPLEX_FLOAT,
    MODE_VECTOR_INT,
    MODE_VECTOR_FLOAT,
    MAX_MODE_CLASS
};


enum reg_class {
    NO_REGS,
    AREG,
    DREG,
    CREG,
    BREG,
    SIREG,
    DIREG,
    AD_REGS,
    Q_REGS,
    NON_Q_REGS,
    INDEX_REGS,
    LEGACY_REGS,
    GENERAL_REGS,
    FP_TOP_REG,
    FP_SECOND_REG,
    FLOAT_REGS,
    SSE_REGS,
    MMX_REGS,
    FP_TOP_SSE_REGS,
    FP_SECOND_SSE_REGS,
    FLOAT_SSE_REGS,
    FLOAT_INT_REGS,
    INT_SSE_REGS,
    FLOAT_INT_SSE_REGS,
    ALL_REGS,
    LIM_REG_CLASSES
};


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


extern int target_flags;
extern HARD_REG_ELT_TYPE reg_class_contents[25];
extern const enum mode_class mode_class[59];
extern const unsigned char mode_size[59];
extern enum reg_class class;
extern enum machine_mode mode;
extern int regno;
extern int sr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive and cache-friendly access pattern
    // Reorder computation to access memory sequentially by precomputing conditions
    // and iterating in natural order with local accumulation

    // Precompute initial value of sr without modifying original logic
    int computed_sr = (((regno) >= 8 && (regno) <= (8 + 7)) || 
                       (((regno) >= (20 + 1) && (regno) <= ((20 + 1) + 7)) || 
                        ((regno) >= ((((((((20 + 1) + 7) + 1) + 7) + 1) + 7) + 1) + 7) && 
                         (regno) <= ((((((((20 + 1) + 7) + 1) + 7) + 1) + 7) + 1) + 7))) || 
                       ((regno) >= (((20 + 1) + 7) + 1) && (regno) <= ((((20 + 1) + 7) + 1) + 7)) ? 
                          (((mode_class[(int)(mode)]) == MODE_COMPLEX_INT || 
                            (mode_class[(int)(mode)]) == MODE_COMPLEX_FLOAT) ? 2 : 1) : 
                          ((mode) == TFmode ? ((target_flags & 33554432) ? 2 : 3) : 
                           (mode) == TCmode ? ((target_flags & 33554432) ? 4 : 6) : 
                           (((mode_size[(int)(mode)]) + ((target_flags & 33554432) ? 8 : 4) - 1) / ((target_flags & 33554432) ? 8 : 4)))) - 1;

    // Use a temporary array to simulate consecutive access to bit masks
    HARD_REG_ELT_TYPE masks[64]; // Assume max possible sr is less than 64
    int i;
    for (i = 1; i <= computed_sr && i < 64; i++) {
        masks[i] = ((HARD_REG_ELT_TYPE)(1)) << (regno + i); // Precomputed consecutive accesses
    }

    // Now iterate forward (consecutive access to masks[]) while checking condition
    for (sr = computed_sr; sr > 0; sr--) {
        if (!(reg_class_contents[(int)class] & masks[sr])) {
            break;
        }
    }
}
