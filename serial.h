
#ifndef SERIAL_H
#define SERIAL_H

#define SMR_1 (*(volatile unsigned char*)  (0xffff88)) /* Serial 1 Mode */
#define BRR_1 (*(volatile unsigned char*)  (0xffff89)) /* Serial 1 Bit Rate */
#define SCR_1 (*(volatile unsigned char*)  (0xffff8a)) /* Serial 1 Serial Control */
#define TDR_1 (*(volatile unsigned char*)  (0xffff8b)) /* Serial 1 Transmit Data */
#define SSR_1 (*(volatile unsigned char*)  (0xffff8c)) /* Serial 1 Serial Status */
#define RDR_1 (*(volatile unsigned char*)  (0xffff8d)) /* Serial 1 Receive Data */
#define SCMR_1 (*(volatile unsigned char*)  (0xffff8e)) /* Serial 1 Smart Card Mode */

/* SCI SCL register bit definitions */
#define SCR_TIE   (1 << 7)
#define SCR_RIE   (1 << 6)
#define SCR_TE    (1 << 5)
#define SCR_RE    (1 << 4)
#define SCR_MPIE  (1 << 3)
#define SCR_TEIE  (1 << 2)
#define SCR_CKE1  (1 << 1)
#define SCR_CKE0  (1 << 0)

/* SCI SMR register bit definitions */
#define SMR_C_nA    (1 << 7) /* communication mode. 0 -> async, 1 -> clocked sync */
#define SMR_CHR     (1 << 6) /* character lenght 0 -> 8bits, 1 -> 7bits */
#define SMR_PE      (1 << 5) /* parity enable */
#define SMR_O_nE    (1 << 4) /* parity mode 0 -> even, 1 -> odd */
#define SMR_STOP    (1 << 3) /* parirty stop bit lenght 0 -> 1 stop bits, 1 -> 2 stop bits*/
#define SMR_MP      (1 << 2) /* multiprocess mode enable */
#define SMR_CKS1    (1 << 1) /* see baudrate calculation */
#define SMR_CKS0    (1 << 0) /* see baudrate calculation */

/* SCI SSR register bit definitions */
#define SSR_TDRE    (1 << 7) /* transmit data register empty */
#define SSR_RDRF    (1 << 6) /* receive data register full */
#define SSR_ORER    (1 << 5) /* Overrun Error */
#define SSR_FER     (1 << 4) /* Framing Error */
#define SSR_PER     (1 << 3) /* Parity Error */
#define SSR_TEND    (1 << 2) /* Transmit End */
#define SSR_MPB     (1 << 1) /* Multiprocessor Bit */
#define SSR_MPBT    (1 << 0) /* Multiprocessor Bit Transfer */


enum e_baudrate {
	B4800 = 0,
	B9600,
	B19200,
	B31250,
	B38400,
};

void uart_putc(const char c);
int setup_serial(enum e_baudrate baudrate, short enable_interupts);

#endif /* SERIAL_H */