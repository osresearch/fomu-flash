#ifndef BB_SPI_H_
#define BB_SPI_H_

#include <stdint.h>

enum spi_state {
	SS_UNCONFIGURED = 0,
	SS_SINGLE,
	SS_DUAL_RX,
	SS_DUAL_TX,
	SS_QUAD_RX,
	SS_QUAD_TX,
	SS_HARDWARE,
};

enum spi_type {
	ST_UNCONFIGURED,
	ST_SINGLE,
	ST_DUAL,
	ST_QUAD,
	ST_QPI,
};

enum spi_pin {
	SP_MOSI,
	SP_MISO,
	SP_HOLD,
	SP_WP,
	SP_CS,
	SP_CLK,
	SP_D0,
	SP_D1,
	SP_D2,
	SP_D3,
};

struct ff_spi;

void spiPause(struct ff_spi *spi);
void spiBegin(struct ff_spi *spi);
void spiEnd(struct ff_spi *spi);

//void spiSingleTx(struct ff_spi *spi, uint8_t out);
//uint8_t spiSingleRx(struct ff_spi *spi);
//void spiDualTx(struct ff_spi *spi, uint8_t out);
//void spiQuadTx(struct ff_spi *spi, uint8_t out);
void spiCommand(struct ff_spi *spi, uint8_t cmd);
//uint8_t spiDualRx(struct ff_spi *spi);
//uint8_t spiQuadRx(struct ff_spi *spi);
int spiTx(struct ff_spi *spi, uint8_t word);
uint8_t spiRx(struct ff_spi *spi);
uint8_t spiReadSr(struct ff_spi *spi, int sr);
void spiWriteSr(struct ff_spi *spi, int sr, uint8_t val);
int spiSetType(struct ff_spi *spi, enum spi_type type);
int spiRead(struct ff_spi *spi, uint32_t addr, uint8_t *data, unsigned int count);
//int spi_wait_for_not_busy(struct ff_spi *spi);
int spiWrite(struct ff_spi *spi, uint32_t addr, const uint8_t *data, unsigned int count);
uint8_t spiReset(struct ff_spi *spi);
int spiInit(struct ff_spi *spi);

void spiHold(struct ff_spi *spi);
void spiUnhold(struct ff_spi *spi);
void spiSwapTxRx(struct ff_spi *spi);

struct ff_spi *spiAlloc(void);
void spiSetPin(struct ff_spi *spi, enum spi_pin pin, int val);
void spiFree(struct ff_spi **spi);

#endif /* BB_SPI_H_ */