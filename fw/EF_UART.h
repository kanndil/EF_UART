/*! \file EF_UART.h
    \brief C header file for UART APIs which contains the function prototypes 
    
*/


#ifndef EF_UART_H
#define EF_UART_H

#include <EF_UART_regs.h>
#include <stdint.h>
#include <stdbool.h>
#include <version.h>

// UART API and Driver version
#define EF_UART_API_VERSION 0x0001
#define EF_UART_DRV_VERSION 0x0001

// UART Parity control types
enum parity_type {NONE = 0, ODD = 1, EVEN = 2, STICKY_0 = 4, STICKY_1 = 5};


// Function documentation
/** 
    \fn     DRIVER_VERSION EF_UART_getVersion(void)
    \brief  Get the version of the UART APIs and driver.
    \return \ref DRIVER_VERSION structure which contains the version of the driver.

    \fn     void EF_UART_initiate(uint32_t uart_base)
    \brief  Initialize the UART driver. 
            Given the base memory address of the UART registers, this function initializes the UART registers structure. \ref EF_UART_REGS.
    \param  uart_base The base memory address of UART registers.
    \return none

    \fn     void EF_UART_enable(void)
    \brief  Enable UART by setting "en" bit in the control register to 1.
    \return none

    \fn     void EF_UART_disable(void)
    \brief  Disable UART by clearing "en" bit in the control register.
    \return none

    \fn     void EF_UART_setGclkEnable(uint32_t value)
    \brief  Enable the UART clock gating.
    \param  a value to set the GCLK register to. 
    \return none

    \fn     void EF_UART_enableRx(void)
    \brief  Enable UART RX by setting uart "rxen" bit in the control register to 1.
    \return none

    \fn     void EF_UART_disableRx(void)
    \brief  Disable UART RX by clearing uart "rxen" bit in the control register.
    \return none

    \fn     void EF_UART_enableTx(void)
    \brief  Enable UART TX by setting uart "txen" bit in the control register to 1.
    \return none

    \fn     void EF_UART_disableTx(void)
    \brief  Disable UART TX by clearing uart "txen" bit in the control register.
    \return none

    \fn     void EF_UART_enableLoopBack(void)
    \brief  Enable loopback (connecting TX to RX signal) by setting "lpen" bit in the control register to 1.
    \return none

    \fn     void EF_UART_disableLoopBack(void)
    \brief  Disable loopback (connecting TX to RX signal) by clearing "lpen" bit in the control register.
    \return none

    \fn     void EF_UART_enableGlitchFilter(void)
    \brief  Enable glitch filter (filter out noise or glitches on the received signal) by setting "gfen" bit in the control register to 1.
    \return none

    \fn     void EF_UART_disableGlitchFilter(void)
    \brief  Disable glitch filter (filter out noise or glitches on the received signal) by clearing "gfen" bit in the control register.
    \return none

    \fn     void EF_UART_setCTRL(uint32_t value)
    \brief  Set the control register to a certain value where
            *  bit 0: UART enable
            *  bit 1: UART Transmitter enable
            * bit 2: UART Receiver enable
            * bit 3: Loopback (connect RX and TX pins together) enable
            * bit 4: UART Glitch Filer on RX enable
    \param  value The value of the control register
    \return none

    \fn     uint32_t EF_UART_getCTRL(void)
    \brief  Get the value of the control register.
    \return A uint32_t value of the control register.

    \fn     void EF_UART_setDataSize(uint32_t value)
    \brief  Set the Data Size (Data word length: 5-9 bits ) by setting the "wlen" field in configuration register
    \param  value The value of the required data word length
    \return none

    \fn     void EF_UART_setTwoStopBitsSelect(bool is_two_bits)
    \brief  Set the "stp2" bit in configuration register (whether the stop boits are two or one)
    \param  is_two_bits bool value, if "true", the stop bits are two and if "false", the stop bit is one
    \return none

    \fn     void EF_UART_setParityType(enum parity_type parity)
    \brief  Set the "parity" field  in configuration register (could be none, odd, even, sticky 0 or sticky 1)
    \param  parity enum parity_type could be "NONE" , "ODD" , "EVEN" ,  "STICKY_0" , or  "STICKY_1"
    \return none

    \fn     void EF_UART_setTimeoutBits(uint32_t value)
    \brief  Set the "timeout" field in configuration register which is receiver timeout measured in number of bits at which the timeout flag will be raised
    \param  value timeout bits value
    \return none

    \fn     void EF_UART_setConfig(uint32_t config)
    \brief  Set the configuration register to a certain value where
            *  bit 0-3: Data word length: 5-9 bits
            *  bit 4: Two Stop Bits Select
            *  bit 5-7: Parity Type: 000: None, 001: odd, 010: even, 100: Sticky 0, 101: Sticky 1
            *  bit 8-13: Receiver Timeout measured in number of bits
    \param  config The value of the configuration register
    \return none


    \fn     uint32_t EF_UART_getConfig(void)
    \brief  Get the value of the configuration register.
    \return A uint32_t value of the configuration register.

    \fn     void EF_UART_setRxFIFOThreshold(uint32_t threshold)
    \brief  Set the RX FIFO threshold to a certain value at which "RXA" interrupt will be raised
    \param  threshold The value of the required threshold
    \return none

    \fn     uint32_t EF_UART_getRxFIFOThreshold(void)
    \brief  Get the value of the RX FIFO threshold register.
    \return A uint32_t value of the RX FIFO threshold register.

    \fn     void EF_UART_setTxFIFOThreshold(uint32_t threshold)
    \brief  Set the TX FIFO threshold to a certain value at which "TXB" interrupt will be raised
    \param  threshold The value of the required threshold
    \return none

    \fn     uint32_t EF_UART_getTxFIFOThreshold(void)
    \brief  Get the value of the TX FIFO threshold register.
    \return A uint32_t value of the TX FIFO threshold register.

    \fn     void EF_UART_setMatchData(uint32_t matchData)
    \brief  Set the matchData to a certain value at which "MATCH" interrupt will be raised
    \param  matchData The value of the required match data
    \return none

    \fn     uint32_t EF_UART_getMatchData(void)
    \brief  Get the value of the match data register.
    \return A uint32_t value of the match data register.

    \fn     uint32_t EF_UART_getTxCount(void)
    \brief  Get the TX FIFO level register which is the number of bytes in the FIFO
    \return A uint32_t value of the TX FIFO level register.

    \fn     uint32_t EF_UART_getRxCount(void)
    \brief  Get the RX FIFO level register which is the number of bytes in the FIFO
    \return A uint32_t value of the RX FIFO level register.

    \fn     void EF_UART_setPrescaler(uint32_t prescaler)
    \brief  Set the prescaler to a certain value where Baud_rate = Bus_Clock_Freq/((Prescaler+1)*16)
    \param  prescaler The value of the required prescaler
    \return none

    \fn     uint32_t EF_UART_getPrescaler(void) 
    \brief  Get the value of the prescaler register.
    \return A uint32_t value of the prescaler register.

    \fn     uint32_t EF_UART_getRIS(void)
    \brief  Get the value of the Raw Interrupt Status Register
            *  bit 0 TXE : Transmit FIFO is Empty.
            *  bit 1 RXF :  Receive FIFO is Full.
            *  bit 2 TXB : Transmit FIFO level is Below Threshold.
            *  bit 3 RXA : Receive FIFO level is Above Threshold.
            *  bit 4 BRK : Line Break; 13 consecutive 0's have been detected on the line.
            *  bit 5 MATCH : the receive data matches the MATCH register.
            *  bit 6 FE : Framing Error, the receiver does not see a "stop" bit at the expected "stop" bit time.
            *  bit 7 PRE : Parity Error; the receiver calculated parity does not match the received one.
            *  bit 8 OR : Overrun; data has been received but the RX FIFO is full.
            *  bit 9 RTO : Receiver Timeout; no data has been received for the time of a specified number of bits.
    \return A uint32_t value of the RIS register.

    \fn     uint32_t EF_UART_getMIS(void)
    \brief  Get the value of the Masked Interrupt Status Register
            *  bit 0 TXE : Transmit FIFO is Empty.
            *  bit 1 RXF :  Receive FIFO is Full.
            *  bit 2 TXB : Transmit FIFO level is Below Threshold.
            *  bit 3 RXA : Receive FIFO level is Above Threshold.
            *  bit 4 BRK : Line Break; 13 consecutive 0's have been detected on the line.
            *  bit 5 MATCH : the receive data matches the MATCH register.
            *  bit 6 FE : Framing Error, the receiver does not see a "stop" bit at the expected "stop" bit time.
            *  bit 7 PRE : Parity Error; the receiver calculated parity does not match the received one.
            *  bit 8 OR : Overrun; data has been received but the RX FIFO is full.
            *  bit 9 RTO : Receiver Timeout; no data has been received for the time of a specified number of bits.
    \return A uint32_t value of the MIS register.

    \fn     void EF_UART_setIM(uint32_t mask)
    \brief  Set the value of the Interrupts Masking Register; which enable and disables interrupts
            *  bit 0 TXE : Transmit FIFO is Empty.
            *  bit 1 RXF :  Receive FIFO is Full.
            *  bit 2 TXB : Transmit FIFO level is Below Threshold.
            *  bit 3 RXA : Receive FIFO level is Above Threshold.
            *  bit 4 BRK : Line Break; 13 consecutive 0's have been detected on the line.
            *  bit 5 MATCH : the receive data matches the MATCH register.
            *  bit 6 FE : Framing Error, the receiver does not see a "stop" bit at the expected "stop" bit time.
            *  bit 7 PRE : Parity Error; the receiver calculated parity does not match the received one.
            *  bit 8 OR : Overrun; data has been received but the RX FIFO is full.
            *  bit 9 RTO : Receiver Timeout; no data has been received for the time of a specified number of bits.
    \param  mask The required mask value
    \return none

    \fn     uint32_t EF_UART_getIM(void)
    \brief  Get the value of the Interrupts Masking Register; which enable and disables interrupts
            *  bit 0 TXE : Transmit FIFO is Empty.
            *  bit 1 RXF :  Receive FIFO is Full.
            *  bit 2 TXB : Transmit FIFO level is Below Threshold.
            *  bit 3 RXA : Receive FIFO level is Above Threshold.
            *  bit 4 BRK : Line Break; 13 consecutive 0's have been detected on the line.
            *  bit 5 MATCH : the receive data matches the MATCH register.
            *  bit 6 FE : Framing Error, the receiver does not see a "stop" bit at the expected "stop" bit time.
            *  bit 7 PRE : Parity Error; the receiver calculated parity does not match the received one.
            *  bit 8 OR : Overrun; data has been received but the RX FIFO is full.
            *  bit 9 RTO : Receiver Timeout; no data has been received for the time of a specified number of bits.
    \return A uint32_t value of the IM register.

    \fn     void EF_UART_setICR(uint32_t mask)
    \brief  sets the value of the Interrupts Clear Register; write 1 to clear the flag
            *  bit 0 TXE : Transmit FIFO is Empty.
            *  bit 1 RXF :  Receive FIFO is Full.
            *  bit 2 TXB : Transmit FIFO level is Below Threshold.
            *  bit 3 RXA : Receive FIFO level is Above Threshold.
            *  bit 4 BRK : Line Break; 13 consecutive 0's have been detected on the line.
            *  bit 5 MATCH : the receive data matches the MATCH register.
            *  bit 6 FE : Framing Error, the receiver does not see a "stop" bit at the expected "stop" bit time.
            *  bit 7 PRE : Parity Error; the receiver calculated parity does not match the received one.
            *  bit 8 OR : Overrun; data has been received but the RX FIFO is full.
            *  bit 9 RTO : Receiver Timeout; no data has been received for the time of a specified number of bits.
    \param  mask The required mask value
    \return none

    \fn     void EF_UART_writeCharArr(const char *char_arr)
    \brief  transmit an array of characters through uart
    \param  char_arr An array of characters to send
    \return none

    \fn     void EF_UART_writeChar(char data)
    \brief  transmit a single character through uart
    \param  data The character or byte required to send
    \return none

    \fn     uint32_t EF_UART_readChar(void)
    \brief  recieve a single character through uart
    \return A uint32_t value of the byte recieved

*/



/**
 * @brief UART Driver Access Structure
 *
 * This structure defines the UART driver.
 *
 * The driver structure contains function pointers to the driver functions.
 *
 * The driver functions are used to interact with the UART hardware.
 */
typedef struct _EF_DRIVER_UART_ {
    EF_UART_REGS *UART_REGS;                            ///< Pointer to the UART registers structure. This is the base address of the UART registers.
                                                        ///< This pointer should be set by the driver initialization function \ref EF_UART_initialize.

    DRIVER_VERSION (*getVersion)(void);                 ///< Pointer to /ref EF_UART_getVersion function: Function to get the version of the UART APIs and driver.
    void (*initialize)(uint32_t uart_base);             ///< Pointer to /ref EF_UART_initialize function: Function to initialize the UART driver.
    void (*enable)(void);                               ///< Pointer to /ref EF_UART_enable function: Function to enable the UART.
    void (*disable)(void);                              ///< Pointer to /ref EF_UART_disable function: Function to disable the UART.
    void (*setGclkEnable)(uint32_t value);               ///< Pointer to /ref EF_UART_setGclkEnable function: Function to enable or disable the Clock Gating.
    void (*enableRx)(void);                             ///< Pointer to /ref EF_UART_enableRx function: Function to enable the UART RX.
    void (*disableRx)(void);                            ///< Pointer to /ref EF_UART_disableRx function: Function to disable the UART RX.
    void (*enableTx)(void);                             ///< Pointer to /ref EF_UART_enableTx function: Function to enable the UART TX.
    void (*disableTx)(void);                            ///< Pointer to /ref EF_UART_disableTx function: Function to disable the UART TX.
    void (*enableLoopBack)(void);                       ///< Pointer to /ref EF_UART_enableLoopBack function: Function to enable the UART Loopback.
    void (*disableLoopBack)(void);                      ///< Pointer to /ref EF_UART_disableLoopBack function: Function to disable the UART Loopback.
    void (*enableGlitchFilter)(void);                   ///< Pointer to /ref EF_UART_enableGlitchFilter function: Function to enable the UART Glitch Filter.
    void (*disableGlitchFilter)(void);                  ///< Pointer to /ref EF_UART_disableGlitchFilter function: Function to disable the UART Glitch Filter.
    void (*setCTRL)(uint32_t value);                    ///< Pointer to /ref EF_UART_setCTRL function: Function to set the UART Control Register.
    uint32_t (*getCTRL)(void);                          ///< Pointer to /ref EF_UART_getCTRL function: Function to get the UART Control Register.
    void (*setDataSize)(uint32_t value);                ///< Pointer to /ref EF_UART_setDataSize function: Function to set the Data Size.
    void (*setTwoStopBitsSelect)(bool is_two_bits);     ///< Pointer to /ref EF_UART_setTwoStopBitsSelect function: Function to set the Two Stop Bits Select.
    void (*setParityType)(enum parity_type parity);     ///< Pointer to /ref EF_UART_setParityType function: Function to set the Parity Type.
    void (*setTimeoutBits)(uint32_t value);              ///< Pointer to /ref EF_UART_setTimeoutBits function: Function to set the Timeout Bits.
    void (*setConfig)(uint32_t config);                  ///< Pointer to /ref EF_UART_setConfig function: Function to set the Configuration Register.
    uint32_t (*getConfig)(void);                         ///< Pointer to /ref EF_UART_getConfig function: Function to get the Configuration Register.
    void (*setRxFIFOThreshold)(uint32_t threshold);      ///< Pointer to /ref EF_UART_setRxFIFOThreshold function: Function to set the RX FIFO Threshold.
    uint32_t (*getRxFIFOThreshold)(void);                ///< Pointer to /ref EF_UART_getRxFIFOThreshold function: Function to get the RX FIFO Threshold.
    void (*setTxFIFOThreshold)(uint32_t threshold);      ///< Pointer to /ref EF_UART_setTxFIFOThreshold function: Function to set the TX FIFO Threshold.
    uint32_t (*getTxFIFOThreshold)(void);                ///< Pointer to /ref EF_UART_getTxFIFOThreshold function: Function to get the TX FIFO Threshold.
    void (*setMatchData)(uint32_t matchData);            ///< Pointer to /ref EF_UART_setMatchData function: Function to set the Match Data.
    uint32_t (*getMatchData)(void);                      ///< Pointer to /ref EF_UART_getMatchData function: Function to get the Match Data.
    uint32_t (*getTxCount)(void);                        ///< Pointer to /ref EF_UART_getTxCount function: Function to get the TX FIFO Level, the number of bytes in the FIFO.
    uint32_t (*getRxCount)(void);                        ///< Pointer to /ref EF_UART_getRxCount function: Function to get the RX FIFO Level, the number of bytes in the FIFO.
    void (*setPrescaler)(uint32_t prescaler);            ///< Pointer to /ref EF_UART_setPrescaler function: Function to set the Prescaler.
    uint32_t (*getPrescaler)(void);                      ///< Pointer to /ref EF_UART_getPrescaler function: Function to get the Prescaler.
    uint32_t (*getRIS)(void);                            ///< Pointer to /ref EF_UART_getRIS function: Function to get the Raw Interrupt Status Register.        
    uint32_t (*getMIS)(void);                            ///< Pointer to /ref EF_UART_getMIS function: Function to get the Masked Interrupt Status Register.
    void (*setIM)(uint32_t mask);                        ///< Pointer to /ref EF_UART_setIM function: Function to set the Interrupts Masking Register.
    uint32_t (*getIM)(void);                             ///< Pointer to /ref EF_UART_getIM function: Function to get the Interrupts Masking Register.
    void (*setICR)(uint32_t mask);                       ///< Pointer to /ref EF_UART_setICR function: Function to set the Interrupts Clear Register.
    void (*writeCharArr)(const char *char_arr);         ///< Pointer to /ref EF_UART_writeCharArr function: Function to transmit an array of characters through UART.
    void (*writeChar)(char data);                       ///< Pointer to /ref EF_UART_writeChar function: Function to transmit a single character through UART.
    uint32_t (*readChar)(void);                          ///< Pointer to /ref EF_UART_readChar function: Function to receive a single character through UART.
} EF_DRIVER_UART;




#endif