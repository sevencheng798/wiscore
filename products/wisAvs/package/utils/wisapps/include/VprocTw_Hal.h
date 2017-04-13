#include <sys/ioctl.h>
#include <linux/types.h>
//#include "zl380tw.h"
#include <linux/spi/zl380tw.h>

int gTwolf_fd;
extern int VprocHALInit(void);
extern void VprocHALcleanup(void);
extern int VprocHALread(unsigned char *pData, unsigned short numBytes);
extern int VprocHALwrite(unsigned char *pData, unsigned short numBytes);
extern int ioctlHALfunctions (unsigned int cmd, void* arg); 
