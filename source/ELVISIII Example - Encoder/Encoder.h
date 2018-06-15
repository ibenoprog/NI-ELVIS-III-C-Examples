/**
 * Encoder.h
 *
 * Copyright (c) 2018,
 * National Instruments Corporation.
 * All rights reserved.
 */

#ifndef Encoder_h_
#define Encoder_h_

#include "NiELVISIIIv10.h"

//Encoder channel selection number
#define ENCODER_NUM 10

#if NiFpga_Cpp
extern "C" {
#endif

/**
 * Specify the numbers of encoder channels.
 *
 * Encoder_Channel0: 0
 * Encoder_Channel1: 1
 * ...
 * Encoder_Channel9: 9
 */
typedef enum
{
    Encoder_Channel0 = 0,
    Encoder_Channel1 = 1,
    Encoder_Channel2 = 2,
    Encoder_Channel3 = 3,
    Encoder_Channel4 = 4,
    Encoder_Channel5 = 5,
    Encoder_Channel6 = 6,
    Encoder_Channel7 = 7,
    Encoder_Channel8 = 8,
    Encoder_Channel9 = 9,
} Encoder_Channel;


/**
 * Flags that indicate which of the encoder configure functions are set.
 */
typedef enum
{
    Encoder_Enable = 0x01,      /**< The encoder enable option is set */
    Encoder_Reset = 0x02,       /**< The encoder reset counter option is set */
    Encoder_SignalMode = 0x04,  /**< The encoder signal mode option is set */
    Encoder_Error = 0x08,       /**< The encoder clear error option is set */
    Encoder_Overflow = 0x10     /**< The encoder clear overflow option is set */
} Encoder_ConfigureMask;


/**
 * Encoder configuration register options.
 */
typedef enum
{
    Encoder_Disabled = 0x00,        /**< Encoder is not enabled */
    Encoder_Enabled = 0x01,         /**< Encoder is enabled */
    Encoder_ResetCounter = 0x02,    /**< Reset the value of the counter to 0. The counter remains at 0 as long as the bit has a value of 1 */
    Encoder_QuadPhase = 0x00,       /**< Operate in quad phase mode */
    Encoder_StepDirection = 0x04,   /**< Operate in step and direction mode */
    Encoder_ClearError = 0x08,      /**< Clears the error flag in the status register */
    Encoder_ClearOverflow = 0x10    /**< Clears the overflow flags in the status register */
} Encoder_ConfigureSettings;


/**
 * Flags for the status register values. Bitwise OR with the value returned from
 * ENC_Status to determine the value or the register.
 */
typedef enum
{
    Encoder_StDirection = 0x01,             /**< Last direction change to the encoder counter value. 0 indicates increment, 1 indicates decrement */
    Encoder_StError = 0x02,                 /**< 1 if an error occurred */
    Encoder_StUnsignedOverflow = 0x04,      /**< 1 if overflow occurred */
    Encoder_StSignedOverflow = 0x08,        /**< 1 if overflow occurred */
    Encoder_StUnsignedOverflowError = 0x10, /**< 1 if an error occurred */
    Encoder_StSignedOverflowError = 0x20    /**< 1 if an error occurred */
} Encoder_StatusMask;


/**
 * Direction from the encoder.
 */
typedef enum
{
    Encoder_Incrementing = 0x00,   /**< Last encoder change was incrementing */
    Encoder_Decrementing = 0x01,   /**< Last encoder change was decrementing */
} Encoder_Direction;


/**
 * Registers for a particular encoder.
 */
typedef struct
{
    uint32_t cnfg[ENCODER_NUM];  /**< Encoder Configuration Register */
    uint32_t stat[ENCODER_NUM];  /**< Encoder Status Register */
    uint32_t cntr[ENCODER_NUM];  /**< Encoder Value Register */
    uint32_t sel;                /**< System Select Register */
} ELVISIII_Encoder;


/**
 * Set the encoder options.
 */
void Encoder_Configure(ELVISIII_Encoder*         connector,
                       Encoder_Channel           channel,
                       Encoder_ConfigureMask     mask,
                       Encoder_ConfigureSettings settings);


/**
 * Gets the status of the encoder.
 */
uint8_t Encoder_Status(ELVISIII_Encoder* connector, Encoder_Channel channel);


/**
 * Gets the value of the counter (the number of steps the encoder has taken).
 */
uint32_t Encoder_Counter(ELVISIII_Encoder* connector, Encoder_Channel channel);


/**
 * Write the value to the System Select Register.
 */
void Encoder_Select(ELVISIII_Encoder* connector, Encoder_Channel channel);


#if NiFpga_Cpp
}
#endif

#endif /* Encoder_h_ */
