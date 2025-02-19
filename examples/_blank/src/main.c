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
    uint16_t rsn = rstrsn();
    
    // IWDT -> Independent Watchdog Timer
    iwdt_disable(); // 禁用看门狗
    
    dbgInit();
    debug("Start(rsn:0x%X)...\r\n", rsn);
}


static void userProc(void)
{
    // Todo user procedure
    
}

int main(void)
{
    sysInit();
    devInit();
    
    while (1)
    {
        userProc();
    }
}
