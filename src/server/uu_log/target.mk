TARGET = uu_log
LIBS += base
INC_DIR += $(PRG_DIR)/include

SRC_CC = main.cc\
	 uu_log.cc\
	 uu_uart.cc

SRC_CC += udrv_cp210x.cc

vpath %.cc 	$(PRG_DIR)
vpath udrv_%.cc	$(PRG_DIR)/drivers
