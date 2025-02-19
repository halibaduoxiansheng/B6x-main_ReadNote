/**
 ****************************************************************************************
 *
 * @file cfg.h
 *
 * @brief App Configure MACRO, --preinclude
 *
 ****************************************************************************************
 */

#ifndef _APP_CFG_H_
#define _APP_CFG_H_

/// System Clock(0=16MHz, 1=32MHz, 2=48MHz, 3=64MHz)
#define SYS_CLK            (0)

/// Debug Mode: 0=Disable, 1=via UART, 2=RTT Viewer
#define DBG_MODE            (1)

#define SPI_DMA_MODE        (1) // 1=DMA, 0=MCU
#define SPI_FLASH_OP        (0) // 1=Flash, 0=Custom

#define SPI_CS_PAD          (10)
#define SPI_CLK_PAD         (11)
#define SPI_MOSI_PAD        (12) 
#define SPI_MISO_PAD        (13)
#endif  //_APP_CFG_H_
