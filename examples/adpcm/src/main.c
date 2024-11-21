/**
 ****************************************************************************************
 *
 * @file main.c
 *
 * @brief Main Entry of the application.
 *
 ****************************************************************************************
 */

#include "b6x.h"
#include "drvs.h"
#include "adpcm.h"
#include "dbg.h"


/*
 * DEFINES
 ****************************************************************************************
 */



/*
 * FUNCTIONS
 ****************************************************************************************
 */

static void sysInit(void)
{    
    // Todo config, if need
    
}

static void devInit(void)
{
    iwdt_disable();
    
    dbgInit();

    debug("ADPCM Test...\r");
}

/**
 * adpcm -> Adaptive Differential Pulse Code Modulation(自适应 微分 脉冲 代码 调制)
 * 这是一种音频压缩算法，用于减少音频数据的存储需求，广泛应用于语音通信和存储设备中
 * @description: 使用了ADPCM编码器和解码器来验证音频数据在压缩和还原过程中的完整性
 * we can find ,set output model first ,then high level work, low level stop -> GPIO08
 */
static void adpcmTest(void)
{
    struct adpcm_state state;
    int iRead = 128; // size of data
    uint16_t rawBuff[128] = {0};
    uint8_t  wavBuff[64] = {0};
    
    /**
     * input model just only read
     * output model can set level
     */
    GPIO_DIR_SET_LO(GPIO08);
    /*init rawBuff data as fake data*/
    for (uint16_t i = 0; i < 128; i++)
    {
        rawBuff[i] = 0x08*i;
    }
    debug("RAW0:\r\n");
    debugHex(rawBuff, 128); /*Print*/
    
    /*resume adpcb status*/
    state.index = 0;
    state.valprev = 0;

    GPIO_DAT_SET(GPIO08);
    /*Encode data to wavBuff and state*/
    adpcm_coder((short*)rawBuff, (char*)wavBuff, (iRead), &state);
    GPIO_DAT_CLR(GPIO08);
    debug("WAV0(%d,%d):\r\n", state.index, state.valprev); 
    debugHex(wavBuff, 64);
    
    state.index = 0;
    state.valprev = 0;
    memset(rawBuff, 0, sizeof(rawBuff)); /*reset rawBuff*/

    GPIO_DAT_SET(GPIO08);
    /*decoder data from wavBuff*/
    adpcm_decoder((char*)wavBuff, (short*)rawBuff, (iRead), &state);
    GPIO_DAT_CLR(GPIO08);
    debug("RAW1(%d,%d):\r\n", state.index, state.valprev); 
    debugHex(rawBuff, 128);

    state.index = 0;
    state.valprev = 0;
    GPIO_DAT_SET(GPIO08);
    /*Encode data for test again*/
    adpcm_coder((short*)rawBuff, (char*)wavBuff, (iRead), &state);
    GPIO_DAT_CLR(GPIO08);
    debug("WAV1(%d,%d):\r\n", state.index, state.valprev); 
    debugHex(wavBuff, 64);
}

int main(void)
{
    sysInit();
    devInit();

    adpcmTest();
    
    while(1)
    {

    }
}
