#include "iic.h"

#define MMA8451_ADDR 0x1D

#define ADDR_STATUS 0x00
#define ADDR_XYZ_DATA 0x01
#define ADDR_XYZ_DATA_CFG 0x0E
#define ADDR_CTRL_REG1 0x2A
#define ADDR_CTRL_REG4 0x2D
#define ADDR_CTRL_REG5 0x2E
#define ADDR_FF_MT_CFG 0x15
#define ADDR_FF_MT_SRC 0x16
#define ADDR_FF_MT_TH 0x17
#define ADDR_PULSE_CFG 0x21
#define ADDR_PULSE_THSX 0x23
#define ADDR_PULSE_THSY 0x24
#define ADDR_PULSE_THSZ 0x25
#define ADDR_PULSE_TMLT 0x26
#define ADDR_PULSE_LTCY 0x27

void mma8451_init(){
	iic_write(MMA8451_ADDR, ADDR_CTRL_REG1, 0x00);
	iic_write(MMA8451_ADDR, ADDR_XYZ_DATA_CFG, 0x01);	//	+/- 4G
	iic_write(MMA8451_ADDR, ADDR_CTRL_REG4, 0x09);		// Data ready and pulse int
	iic_write(MMA8451_ADDR, ADDR_CTRL_REG5, 0x08);		// pulse on int1 pin, data ready on int2 pin

	iic_write(MMA8451_ADDR, ADDR_PULSE_THSY, 15);		//pulse Y treshold
	iic_write(MMA8451_ADDR, ADDR_PULSE_TMLT, 5);		//tap pulse time limit
	iic_write(MMA8451_ADDR, ADDR_PULSE_CFG, 0x04);
	iic_write(MMA8451_ADDR, ADDR_PULSE_LTCY, 20);		//tap detect latency

	iic_write(MMA8451_ADDR, ADDR_CTRL_REG1, 0x1D);		// 100 Hz
}

