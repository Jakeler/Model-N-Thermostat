#!/bin/sh
sdcc -lstm8 -mstm8 --out-fmt-ihx -o thermo.hex thermo.c
stm8flash -c stlinkv2 -p stm8l152c6 -w thermo.hex
