/****************************************************************************
* Microsemi Semiconductor, Kanata, ON
****************************************************************************
*
* Description: Voice Processor devices high level access module function
*                definitions
*
* NOTE: The registers of the device are 16-bit wide. A 32-bit access
*       is not required. However, the 32-bit access functions are provided
*       only if the host wants to access two consecutives 16-bit registers
*       in one single access.
*  Author: Jean Bony
****************************************************************************
* Copyright Microsemi Semiconductor Ltd., 2013. All rights reserved. This
* copyrighted work constitutes an unpublished work created in 2013. The use
* of the copyright notice is intended to provide notice that Microsemi
* Semiconductor Ltd. owns a copyright in this unpublished work; the main
* copyright notice is not an admission that publication has occurred. This
* work contains confidential, proprietary information and trade secrets of
* Microsemi Semiconductor Ltd.; it may not be used, reproduced or transmitted,
* in whole or in part, in any form or by any means without the prior
* written permission of Microsemi Semiconductor Ltd. This work is provided on
* a right to use basis subject to additional restrictions set out in the
* applicable license or other agreement.
*
***************************************************************************/


#ifndef VPROCTWOLFACCESS_H
#define VPROCTWOLFACCESS_H

#include "vproc_common.h"
#include "VprocTw_Hal.h"

#if 0
#include "VprocTw_Hal.c"
#endif

#define TWOLF_MAILBOX_SPINWAIT  1000  /*at least a 1000 to avoid mailbox busy */


/*device HBI command structure*/
typedef struct hbiCmdInfo {
   unsigned char page;
   unsigned char offset;
   unsigned char numwords;
} hbiCmdInfo;

/* external function prototypes */

extern VprocStatusType VprocTwolfHbiInit(void); /*Use this function to initialize the HBI bus*/

extern VprocStatusType VprocTwolfHbiRead(
    unsigned short cmd,       /*the 16-bit register to read from*/
    unsigned char numwords,   /* The number of 16-bit words to read*/
    unsigned short *pData);   /* Pointer to the read data buffer*/

extern VprocStatusType VprocTwolfHbiWrite(
    unsigned short cmd,     /*the 16-bit register to write to*/
    unsigned char numwords, /* The number of 16-bit words to write*/
    unsigned short *pData); /*the words (0-255) to write*/

extern VprocStatusType TwolfHbiNoOp( /*send no-op command to the device*/
    unsigned char numWords);  /* The number of no-op (0-255) to write*/

/*An alternative method to loading the firmware into the device
* USe this method if you have used the provided tool to convert the *.s3 into
* c code that can be compiled with the application
*/
extern VprocStatusType VprocTwolfHbiBoot_alt( /*use this function to boot load the firmware (*.c) from the host to the device RAM*/
    twFirmware *st_firmware); /*Pointer to the firmware image in host RAM*/

/*An alternative method to loading the firmware into the device
* USe this method if you have not used the provided tool to convert the *.s3 but
* instead prefer to load the *.s3 file directly
*/
extern VprocStatusType VprocTwolfHbiBoot(     /*use this function to boot load the firmware (*.s3) from the host to the device RAM*/
    FILE *BOOT_FD);     /*Pointer to the firmware image in host RAM*/

extern VprocStatusType VprocTwolfLoadConfig(
    dataArr *pCr2Buf,
    unsigned short numElements);
    
extern VprocStatusType VprocTwolfHbiCleanup(void);
extern VprocStatusType VprocTwolfHbiDeviceCheck(void);
extern VprocStatusType VprocTwolfHbiBootPrepare(void);
extern VprocStatusType VprocTwolfHbiBootMoreData(char *dataBlock);
extern VprocStatusType VprocTwolfHbiBootConclude(void);
extern VprocStatusType VprocTwolfFirmwareStop(void);   /*Use this function to halt the currently running firmware*/
extern VprocStatusType VprocTwolfFirmwareStart(void);  /*Use this function to start/restart the firmware currently in RAM*/
extern VprocStatusType VprocTwolfSaveImgToFlash(void);  /*Save current loaded firmware from device RAM to FLASH*/
extern VprocStatusType VprocTwolfSaveCfgToFlash(void); /*Save current device config from device RAM to FLASH*/
extern VprocStatusType VprocTwolfReset(VprocResetMode mode);
extern VprocStatusType VprocTwolfUpstreamConfigure(uint16 clockrate,/*in kHz*/ 
                                       uint16 fsrate,   /*in Hz*/
                                       uint8 aecOn);     /*0 for OFF, 1 for ON*/
extern VprocStatusType VprocTwolfDownstreamConfigure(uint16 clockrate, /*in kHz*/
                                       uint16 fsrate,    /*in Hz*/
                                     uint8 aecOn);      /*0 for OFF, 1 for ON*/
extern VprocStatusType VprocTwolfEraseFlash(void);
extern VprocStatusType VprocTwolfLoadFwrCfgFromFlash(uint16 image_number);
extern VprocStatusType VprocTwolfMute(VprocAudioPortsSel port, uint8 on);
#endif /* VPROCTWOLFACCESS_H */
