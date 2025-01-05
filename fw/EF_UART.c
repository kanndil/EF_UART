/*
	Copyright 2025 Efabless Corp.

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	    www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

*/


/*! \file EF_UART.c
    \brief C file for UART APIs which contains the function implmentations 
    
*/

#ifndef EF_UART_C
#define EF_UART_C

#include <EF_UART.h>
#include <version.h>

#define EF_UART0_BASE ((uint32_t) 0x10000000)       // Base address of the UART registers
                                                    // This is a dummy address, the actual address should be defined in the linker script


#define EF_UART_REG_SPACE ((EF_UART_REGS*)EF_UART0_BASE)


/* Driver Version */
static const DRIVER_VERSION DriverVersion = {
    .api = EF_UART_API_VERSION,
    .drv = EF_UART_DRV_VERSION
};


//
//   Functions
//


static DRIVER_VERSION EF_UART_getVersion(void){

    return DriverVersion;
}

static void EF_UART_enable(void){

    // set the enable bit to 1 at the specified offset
    EF_UART_REG_SPACE->CTRL |= (1 << EF_UART_CTRL_REG_EN_BIT);
    return;
}


static void EF_UART_setGclkEnable (uint32_t value){

    EF_UART_REG_SPACE->GCLK = value;
    return;
}


static void EF_UART_disable(void){

    // Clear the enable bit using the specified  mask
    EF_UART_REG_SPACE->CTRL &= ~EF_UART_CTRL_REG_EN_MASK;
    return;
}


static void EF_UART_enableRx(void){
    
    // set the enable bit to 1 at the specified offset
    EF_UART_REG_SPACE->CTRL |= (1 << EF_UART_CTRL_REG_RXEN_BIT);
    return;
}


static void EF_UART_disableRx(void){
    
    // Clear the enable bit using the specified  mask
    EF_UART_REG_SPACE->CTRL &= ~EF_UART_CTRL_REG_RXEN_MASK;
    return;
}


static void EF_UART_enableTx(void){

    // set the enable bit to 1 at the specified offset
    EF_UART_REG_SPACE->CTRL |= (1 << EF_UART_CTRL_REG_TXEN_BIT);
    return;
}


static void EF_UART_disableTx(void){

    // Clear the enable bit using the specified  mask
    EF_UART_REG_SPACE->CTRL &= ~EF_UART_CTRL_REG_TXEN_MASK;
    return;
}


static void EF_UART_enableLoopBack(void){

    // set the enable bit to 1 at the specified offset
    EF_UART_REG_SPACE->CTRL |= (1 << EF_UART_CTRL_REG_LPEN_BIT);
    return;
}


static void EF_UART_disableLoopBack(void){

    // Clear the enable bit using the specified  mask
    EF_UART_REG_SPACE->CTRL &= ~EF_UART_CTRL_REG_LPEN_MASK;
    return;
}


static void EF_UART_enableGlitchFilter(void){

    // Clear the enable bit using the specified  mask
    EF_UART_REG_SPACE->CTRL &= ~EF_UART_CTRL_REG_GFEN_MASK;

    // set the enable bit to 1 at the specified offset
    EF_UART_REG_SPACE->CTRL |= (1 << EF_UART_CTRL_REG_GFEN_BIT);
    return;
}


static void EF_UART_disableGlitchFilter(void){

    // Clear the enable bit using the specified  mask
    EF_UART_REG_SPACE->CTRL &= ~EF_UART_CTRL_REG_GFEN_MASK;
    return;
}


static void EF_UART_setCTRL(uint32_t value){

    EF_UART_REG_SPACE->CTRL = value;
    return;
}


static uint32_t EF_UART_getCTRL(void){

    return (EF_UART_REG_SPACE->CTRL);
}


static void EF_UART_setDataSize(uint32_t value){

    // Clear the field bits in the register using the defined mask
    EF_UART_REG_SPACE->CFG &= ~EF_UART_CFG_REG_WLEN_MASK;

    // Set the bits with the given value at the defined offset
    EF_UART_REG_SPACE->CFG |= ((value << EF_UART_CFG_REG_WLEN_BIT) & EF_UART_CFG_REG_WLEN_MASK);
    return;
}


static void EF_UART_setPrescaler(uint32_t prescaler){

    EF_UART_REG_SPACE->PR = prescaler;
    return;
}


static uint32_t EF_UART_getPrescaler(void){

    return (EF_UART_REG_SPACE->PR);
}


static void EF_UART_setTwoStopBitsSelect(bool is_two_bits){

    if (is_two_bits){

        // set the enable bit to 1 at the specified offset
        EF_UART_REG_SPACE->CFG |= (1 << EF_UART_CFG_REG_STP2_BIT);

    }
    else {
        // Clear the enable bit using the specified  mask
        EF_UART_REG_SPACE->CFG &= ~EF_UART_CFG_REG_STP2_MASK;
    }
    return;
}

static void EF_UART_setParityType(enum parity_type parity){

    // Clear the field bits in the register using the defined mask
    EF_UART_REG_SPACE->CFG &= ~EF_UART_CFG_REG_PARITY_MASK;

    // Set the bits with the given value at the defined offset
    EF_UART_REG_SPACE->CFG |= ((parity << EF_UART_CFG_REG_PARITY_BIT) & EF_UART_CFG_REG_PARITY_MASK);
    return;
}

static void EF_UART_setTimeoutBits(uint32_t value){

    // Clear the field bits in the register using the defined mask
    EF_UART_REG_SPACE->CFG &= ~EF_UART_CFG_REG_TIMEOUT_MASK;

    // Set the bits with the given value at the defined offset
    EF_UART_REG_SPACE->CFG |= ((value << EF_UART_CFG_REG_TIMEOUT_BIT) & EF_UART_CFG_REG_TIMEOUT_MASK);
    return;
}

static void EF_UART_setConfig(uint32_t value){

    EF_UART_REG_SPACE->CFG = value;
    return;
}

static uint32_t EF_UART_getConfig(void){

    return (EF_UART_REG_SPACE->CFG);
    return;
}

static void EF_UART_setRxFIFOThreshold(uint32_t value){

    EF_UART_REG_SPACE->RX_FIFO_THRESHOLD = value;
    return;
}

static uint32_t EF_UART_getRxFIFOThreshold(void){

    return (EF_UART_REG_SPACE->RX_FIFO_THRESHOLD);
}

static void EF_UART_setTxFIFOThreshold(uint32_t value){

    EF_UART_REG_SPACE->TX_FIFO_THRESHOLD=value;
    return;
}

static uint32_t EF_UART_getTxFIFOThreshold(void){

    return (EF_UART_REG_SPACE->TX_FIFO_THRESHOLD);
}


static uint32_t EF_UART_getTxCount(void){

    return(EF_UART_REG_SPACE->TX_FIFO_LEVEL);
}

static uint32_t EF_UART_getRxCount(void){

    return(EF_UART_REG_SPACE->RX_FIFO_LEVEL);
}


static void EF_UART_setMatchData(uint32_t matchData){

    EF_UART_REG_SPACE->MATCH = matchData;
    return;
}


static uint32_t EF_UART_getMatchData(void){

    return (EF_UART_REG_SPACE->MATCH);
}

 // Interrupts bits in RIS, MIS, IM, and ICR
 // bit 0: TX FIFO is Empty
 // bit 1: TX FIFO level is below the value in the TX FIFO Level Threshold Register
 // bit 2: RX FIFO is Full
 // bit 3: RX FIFO level is above the value in the RX FIFO Level Threshold Register
 // bit 4: line break
 // bit 5: match
 // bit 6: frame error
 // bit 7: parity error
 // bit 8: overrun 
 // bit 9: timeout 

static uint32_t EF_UART_getRIS(void){

    return (EF_UART_REG_SPACE->RIS);
}

static uint32_t EF_UART_getMIS(void){

    return (EF_UART_REG_SPACE->MIS);
}

static void EF_UART_setIM(uint32_t mask){

    EF_UART_REG_SPACE->IM |= mask;
    return;
}

static uint32_t EF_UART_getIM(void){

    return (EF_UART_REG_SPACE->IM);
}

static void EF_UART_setICR(uint32_t mask){

    (EF_UART_REG_SPACE->IC) |= mask;
    return;
}


static void EF_UART_writeChar(char data){

    while((EF_UART_getRIS() & EF_UART_TXE_FLAG) == 0x0); // wait until TX empty flag is 1  
    EF_UART_REG_SPACE->TXDATA = data;
    EF_UART_setICR(EF_UART_TXE_FLAG);
    return;
}

static void EF_UART_writeCharArr(const char *char_arr){

    while (*char_arr){
        while((EF_UART_getRIS() & EF_UART_TXB_FLAG) == 0x0); // wait until tx level below flag is 1
        EF_UART_REG_SPACE->TXDATA = (*(char_arr++));
        EF_UART_setICR(EF_UART_TXB_FLAG);
    }
    return;
}

/*void EF_UART_writeInt(uint32_t uart_base, char data){

    EF_UART_REGS* uart = (EF_UART_REGS*)uart_base;
    while((EF_UART_getRIS(uart_base) & 0x2) == 0x0); // wait when level is above threshold (fifo is full)
    uart->txdata = data;
    EF_UART_setICR(uart_base, 0x2);
}*/

static uint32_t EF_UART_readChar(void){

    while((EF_UART_getRIS() & EF_UART_RXA_FLAG) == 0x0); // wait over RX fifo level above flag to be 1
    uint32_t data = EF_UART_REG_SPACE->RXDATA;
    EF_UART_setICR(EF_UART_RXA_FLAG);

    return data;
}

extern EF_DRIVER_UART EF_DRIVER_UART0;
EF_DRIVER_UART0 =  {
    .UART_REGS = EF_UART_REG_SPACE,
    .getVersion = EF_UART_getVersion,
    .enable = EF_UART_enable,
    .disable = EF_UART_disable,
    .setGclkEnable = EF_UART_setGclkEnable,
    .enableRx = EF_UART_enableRx,
    .disableRx = EF_UART_disableRx,
    .enableTx = EF_UART_enableTx,
    .disableTx = EF_UART_disableTx,
    .enableLoopBack = EF_UART_enableLoopBack,
    .disableLoopBack = EF_UART_disableLoopBack,
    .enableGlitchFilter = EF_UART_enableGlitchFilter,
    .disableGlitchFilter = EF_UART_disableGlitchFilter,
    .setCTRL = EF_UART_setCTRL,
    .getCTRL = EF_UART_getCTRL,
    .setDataSize = EF_UART_setDataSize,
    .setTwoStopBitsSelect = EF_UART_setTwoStopBitsSelect,
    .setParityType = EF_UART_setParityType,
    .setTimeoutBits = EF_UART_setTimeoutBits,
    .setConfig = EF_UART_setConfig,
    .getConfig = EF_UART_getConfig,
    .setRxFIFOThreshold = EF_UART_setRxFIFOThreshold,
    .getRxFIFOThreshold = EF_UART_getRxFIFOThreshold,
    .setTxFIFOThreshold = EF_UART_setTxFIFOThreshold,
    .getTxFIFOThreshold = EF_UART_getTxFIFOThreshold,
    .setMatchData = EF_UART_setMatchData,
    .getMatchData = EF_UART_getMatchData,
    .getTxCount = EF_UART_getTxCount,
    .getRxCount = EF_UART_getRxCount,
    .setPrescaler = EF_UART_setPrescaler,
    .getPrescaler = EF_UART_getPrescaler,
    .getRIS = EF_UART_getRIS,
    .getMIS = EF_UART_getMIS,
    .setIM = EF_UART_setIM,
    .getIM = EF_UART_getIM,
    .setICR = EF_UART_setICR,
    .writeCharArr = EF_UART_writeCharArr,
    .writeChar = EF_UART_writeChar,
    .readChar = EF_UART_readChar
};




#endif // EF_UART_C