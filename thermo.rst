                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module thermo
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _uart_isr
                                     12 	.globl _main
                                     13 	.globl _initClock
                                     14 	.globl _readADC
                                     15 	.globl _initADC
                                     16 	.globl _clearUartBuffer
                                     17 	.globl _readUartBuffer
                                     18 	.globl _uartRead
                                     19 	.globl _uartWrite
                                     20 	.globl _initUSART
                                     21 	.globl _setMotor
                                     22 	.globl _initMotor
                                     23 	.globl _delay
                                     24 	.globl _printf
                                     25 	.globl _strlen
                                     26 	.globl _memset
                                     27 	.globl _dir
                                     28 	.globl _uartBufferPos
                                     29 	.globl _count
                                     30 	.globl _uartBuffer
                                     31 	.globl _putchar
                                     32 ;--------------------------------------------------------
                                     33 ; ram data
                                     34 ;--------------------------------------------------------
                                     35 	.area DATA
      000001                         36 _uartBuffer::
      000001                         37 	.ds 32
                                     38 ;--------------------------------------------------------
                                     39 ; ram data
                                     40 ;--------------------------------------------------------
                                     41 	.area INITIALIZED
      000021                         42 _count::
      000021                         43 	.ds 1
      000022                         44 _uartBufferPos::
      000022                         45 	.ds 1
      000023                         46 _dir::
      000023                         47 	.ds 1
                                     48 ;--------------------------------------------------------
                                     49 ; Stack segment in internal ram 
                                     50 ;--------------------------------------------------------
                                     51 	.area	SSEG
      000024                         52 __start__stack:
      000024                         53 	.ds	1
                                     54 
                                     55 ;--------------------------------------------------------
                                     56 ; absolute external ram data
                                     57 ;--------------------------------------------------------
                                     58 	.area DABS (ABS)
                                     59 ;--------------------------------------------------------
                                     60 ; interrupt vector 
                                     61 ;--------------------------------------------------------
                                     62 	.area HOME
      008000                         63 __interrupt_vect:
      008000 82 00 80 83             64 	int s_GSINIT ;reset
      008004 82 00 00 00             65 	int 0x0000 ;trap
      008008 82 00 00 00             66 	int 0x0000 ;int0
      00800C 82 00 00 00             67 	int 0x0000 ;int1
      008010 82 00 00 00             68 	int 0x0000 ;int2
      008014 82 00 00 00             69 	int 0x0000 ;int3
      008018 82 00 00 00             70 	int 0x0000 ;int4
      00801C 82 00 00 00             71 	int 0x0000 ;int5
      008020 82 00 00 00             72 	int 0x0000 ;int6
      008024 82 00 00 00             73 	int 0x0000 ;int7
      008028 82 00 00 00             74 	int 0x0000 ;int8
      00802C 82 00 00 00             75 	int 0x0000 ;int9
      008030 82 00 00 00             76 	int 0x0000 ;int10
      008034 82 00 00 00             77 	int 0x0000 ;int11
      008038 82 00 00 00             78 	int 0x0000 ;int12
      00803C 82 00 00 00             79 	int 0x0000 ;int13
      008040 82 00 00 00             80 	int 0x0000 ;int14
      008044 82 00 00 00             81 	int 0x0000 ;int15
      008048 82 00 00 00             82 	int 0x0000 ;int16
      00804C 82 00 00 00             83 	int 0x0000 ;int17
      008050 82 00 00 00             84 	int 0x0000 ;int18
      008054 82 00 00 00             85 	int 0x0000 ;int19
      008058 82 00 00 00             86 	int 0x0000 ;int20
      00805C 82 00 00 00             87 	int 0x0000 ;int21
      008060 82 00 00 00             88 	int 0x0000 ;int22
      008064 82 00 00 00             89 	int 0x0000 ;int23
      008068 82 00 00 00             90 	int 0x0000 ;int24
      00806C 82 00 00 00             91 	int 0x0000 ;int25
      008070 82 00 00 00             92 	int 0x0000 ;int26
      008074 82 00 00 00             93 	int 0x0000 ;int27
      008078 82 00 82 C4             94 	int _uart_isr ;int28
      00807C 82 00 00 00             95 	int 0x0000 ;int29
                                     96 ;--------------------------------------------------------
                                     97 ; global & static initialisations
                                     98 ;--------------------------------------------------------
                                     99 	.area HOME
                                    100 	.area GSINIT
                                    101 	.area GSFINAL
                                    102 	.area GSINIT
      008083                        103 __sdcc_gs_init_startup:
      008083                        104 __sdcc_init_data:
                                    105 ; stm8_genXINIT() start
      008083 AE 00 20         [ 2]  106 	ldw x, #l_DATA
      008086 27 07            [ 1]  107 	jreq	00002$
      008088                        108 00001$:
      008088 72 4F 00 00      [ 1]  109 	clr (s_DATA - 1, x)
      00808C 5A               [ 2]  110 	decw x
      00808D 26 F9            [ 1]  111 	jrne	00001$
      00808F                        112 00002$:
      00808F AE 00 03         [ 2]  113 	ldw	x, #l_INITIALIZER
      008092 27 09            [ 1]  114 	jreq	00004$
      008094                        115 00003$:
      008094 D6 8B B3         [ 1]  116 	ld	a, (s_INITIALIZER - 1, x)
      008097 D7 00 20         [ 1]  117 	ld	(s_INITIALIZED - 1, x), a
      00809A 5A               [ 2]  118 	decw	x
      00809B 26 F7            [ 1]  119 	jrne	00003$
      00809D                        120 00004$:
                                    121 ; stm8_genXINIT() end
                                    122 	.area GSFINAL
      00809D CC 80 80         [ 2]  123 	jp	__sdcc_program_startup
                                    124 ;--------------------------------------------------------
                                    125 ; Home
                                    126 ;--------------------------------------------------------
                                    127 	.area HOME
                                    128 	.area HOME
      008080                        129 __sdcc_program_startup:
      008080 CC 82 38         [ 2]  130 	jp	_main
                                    131 ;	return from main will return to caller
                                    132 ;--------------------------------------------------------
                                    133 ; code
                                    134 ;--------------------------------------------------------
                                    135 	.area CODE
                                    136 ;	thermo.c: 24: void delay(uint32_t ms){
                                    137 ;	-----------------------------------------
                                    138 ;	 function delay
                                    139 ;	-----------------------------------------
      0080A0                        140 _delay:
      0080A0 52 0C            [ 2]  141 	sub	sp, #12
                                    142 ;	thermo.c: 25: uint32_t ticks = ms*600/(1 << CLK_CKDIVR);
      0080A2 1E 11            [ 2]  143 	ldw	x, (0x11, sp)
      0080A4 89               [ 2]  144 	pushw	x
      0080A5 1E 11            [ 2]  145 	ldw	x, (0x11, sp)
      0080A7 89               [ 2]  146 	pushw	x
      0080A8 4B 58            [ 1]  147 	push	#0x58
      0080AA 4B 02            [ 1]  148 	push	#0x02
      0080AC 5F               [ 1]  149 	clrw	x
      0080AD 89               [ 2]  150 	pushw	x
      0080AE CD 83 FB         [ 4]  151 	call	__mullong
      0080B1 5B 08            [ 2]  152 	addw	sp, #8
      0080B3 1F 0B            [ 2]  153 	ldw	(0x0b, sp), x
      0080B5 17 09            [ 2]  154 	ldw	(0x09, sp), y
      0080B7 AE 50 C0         [ 2]  155 	ldw	x, #0x50c0
      0080BA F6               [ 1]  156 	ld	a, (x)
      0080BB AE 00 01         [ 2]  157 	ldw	x, #0x0001
      0080BE 4D               [ 1]  158 	tnz	a
      0080BF 27 04            [ 1]  159 	jreq	00117$
      0080C1                        160 00116$:
      0080C1 58               [ 2]  161 	sllw	x
      0080C2 4A               [ 1]  162 	dec	a
      0080C3 26 FC            [ 1]  163 	jrne	00116$
      0080C5                        164 00117$:
      0080C5 90 5F            [ 1]  165 	clrw	y
      0080C7 5D               [ 2]  166 	tnzw	x
      0080C8 2A 02            [ 1]  167 	jrpl	00118$
      0080CA 90 5A            [ 2]  168 	decw	y
      0080CC                        169 00118$:
      0080CC 89               [ 2]  170 	pushw	x
      0080CD 90 89            [ 2]  171 	pushw	y
      0080CF 1E 0F            [ 2]  172 	ldw	x, (0x0f, sp)
      0080D1 89               [ 2]  173 	pushw	x
      0080D2 1E 0F            [ 2]  174 	ldw	x, (0x0f, sp)
      0080D4 89               [ 2]  175 	pushw	x
      0080D5 CD 83 41         [ 4]  176 	call	__divulong
      0080D8 5B 08            [ 2]  177 	addw	sp, #8
      0080DA 1F 07            [ 2]  178 	ldw	(0x07, sp), x
      0080DC 17 05            [ 2]  179 	ldw	(0x05, sp), y
                                    180 ;	thermo.c: 27: for(d = 0; d < ticks; d++) { }
      0080DE 5F               [ 1]  181 	clrw	x
      0080DF 1F 03            [ 2]  182 	ldw	(0x03, sp), x
      0080E1 1F 01            [ 2]  183 	ldw	(0x01, sp), x
      0080E3                        184 00103$:
      0080E3 1E 03            [ 2]  185 	ldw	x, (0x03, sp)
      0080E5 13 07            [ 2]  186 	cpw	x, (0x07, sp)
      0080E7 7B 02            [ 1]  187 	ld	a, (0x02, sp)
      0080E9 12 06            [ 1]  188 	sbc	a, (0x06, sp)
      0080EB 7B 01            [ 1]  189 	ld	a, (0x01, sp)
      0080ED 12 05            [ 1]  190 	sbc	a, (0x05, sp)
      0080EF 24 15            [ 1]  191 	jrnc	00105$
      0080F1 1E 03            [ 2]  192 	ldw	x, (0x03, sp)
      0080F3 1C 00 01         [ 2]  193 	addw	x, #0x0001
      0080F6 1F 03            [ 2]  194 	ldw	(0x03, sp), x
      0080F8 7B 02            [ 1]  195 	ld	a, (0x02, sp)
      0080FA A9 00            [ 1]  196 	adc	a, #0x00
      0080FC 6B 02            [ 1]  197 	ld	(0x02, sp), a
      0080FE 7B 01            [ 1]  198 	ld	a, (0x01, sp)
      008100 A9 00            [ 1]  199 	adc	a, #0x00
      008102 6B 01            [ 1]  200 	ld	(0x01, sp), a
      008104 20 DD            [ 2]  201 	jra	00103$
      008106                        202 00105$:
      008106 5B 0C            [ 2]  203 	addw	sp, #12
      008108 81               [ 4]  204 	ret
                                    205 ;	thermo.c: 31: void initMotor() {
                                    206 ;	-----------------------------------------
                                    207 ;	 function initMotor
                                    208 ;	-----------------------------------------
      008109                        209 _initMotor:
                                    210 ;	thermo.c: 33: PE_DDR |= MOTO_E7 | MOTO_E6;
      008109 AE 50 16         [ 2]  211 	ldw	x, #0x5016
      00810C F6               [ 1]  212 	ld	a, (x)
      00810D AA C0            [ 1]  213 	or	a, #0xc0
      00810F F7               [ 1]  214 	ld	(x), a
                                    215 ;	thermo.c: 34: PE_CR1 |= MOTO_E7 | MOTO_E6;
      008110 AE 50 17         [ 2]  216 	ldw	x, #0x5017
      008113 F6               [ 1]  217 	ld	a, (x)
      008114 AA C0            [ 1]  218 	or	a, #0xc0
      008116 F7               [ 1]  219 	ld	(x), a
                                    220 ;	thermo.c: 35: PE_ODR |= MOTO_E7 | MOTO_E6;
      008117 AE 50 14         [ 2]  221 	ldw	x, #0x5014
      00811A F6               [ 1]  222 	ld	a, (x)
      00811B AA C0            [ 1]  223 	or	a, #0xc0
      00811D F7               [ 1]  224 	ld	(x), a
                                    225 ;	thermo.c: 38: PC_DDR |= MOTO_C4 | MOTO_C7;
      00811E AE 50 0C         [ 2]  226 	ldw	x, #0x500c
      008121 F6               [ 1]  227 	ld	a, (x)
      008122 AA 90            [ 1]  228 	or	a, #0x90
      008124 F7               [ 1]  229 	ld	(x), a
                                    230 ;	thermo.c: 39: PC_CR1 |= MOTO_C4 | MOTO_C7;
      008125 AE 50 0D         [ 2]  231 	ldw	x, #0x500d
      008128 F6               [ 1]  232 	ld	a, (x)
      008129 AA 90            [ 1]  233 	or	a, #0x90
      00812B F7               [ 1]  234 	ld	(x), a
                                    235 ;	thermo.c: 40: PC_ODR |= MOTO_C4 | MOTO_C7;
      00812C AE 50 0A         [ 2]  236 	ldw	x, #0x500a
      00812F F6               [ 1]  237 	ld	a, (x)
      008130 AA 90            [ 1]  238 	or	a, #0x90
      008132 F7               [ 1]  239 	ld	(x), a
      008133 81               [ 4]  240 	ret
                                    241 ;	thermo.c: 44: void setMotor(bool st1, bool st2) {
                                    242 ;	-----------------------------------------
                                    243 ;	 function setMotor
                                    244 ;	-----------------------------------------
      008134                        245 _setMotor:
                                    246 ;	thermo.c: 45: if (st1) {
      008134 0D 03            [ 1]  247 	tnz	(0x03, sp)
      008136 27 09            [ 1]  248 	jreq	00102$
                                    249 ;	thermo.c: 46: PE_ODR &= ~MOTO_E7 & ~MOTO_E6; // 3.3V
      008138 AE 50 14         [ 2]  250 	ldw	x, #0x5014
      00813B F6               [ 1]  251 	ld	a, (x)
      00813C A4 3F            [ 1]  252 	and	a, #0x3f
      00813E F7               [ 1]  253 	ld	(x), a
      00813F 20 07            [ 2]  254 	jra	00103$
      008141                        255 00102$:
                                    256 ;	thermo.c: 48: PE_ODR |= MOTO_E7 | MOTO_E6; // 0V
      008141 AE 50 14         [ 2]  257 	ldw	x, #0x5014
      008144 F6               [ 1]  258 	ld	a, (x)
      008145 AA C0            [ 1]  259 	or	a, #0xc0
      008147 F7               [ 1]  260 	ld	(x), a
      008148                        261 00103$:
                                    262 ;	thermo.c: 50: if (st2) {
      008148 0D 04            [ 1]  263 	tnz	(0x04, sp)
      00814A 27 08            [ 1]  264 	jreq	00105$
                                    265 ;	thermo.c: 51: PC_ODR &= ~MOTO_C4 & ~MOTO_C7; // 3.3V
      00814C AE 50 0A         [ 2]  266 	ldw	x, #0x500a
      00814F F6               [ 1]  267 	ld	a, (x)
      008150 A4 6F            [ 1]  268 	and	a, #0x6f
      008152 F7               [ 1]  269 	ld	(x), a
      008153 81               [ 4]  270 	ret
      008154                        271 00105$:
                                    272 ;	thermo.c: 53: PC_ODR |= MOTO_C4 | MOTO_C7; // 0V
      008154 AE 50 0A         [ 2]  273 	ldw	x, #0x500a
      008157 F6               [ 1]  274 	ld	a, (x)
      008158 AA 90            [ 1]  275 	or	a, #0x90
      00815A F7               [ 1]  276 	ld	(x), a
      00815B 81               [ 4]  277 	ret
                                    278 ;	thermo.c: 59: void initUSART() {
                                    279 ;	-----------------------------------------
                                    280 ;	 function initUSART
                                    281 ;	-----------------------------------------
      00815C                        282 _initUSART:
                                    283 ;	thermo.c: 60: SYSCFG_RMPCR1 |= 0x10; // TX: PA2, RX: PA3
      00815C AE 50 9E         [ 2]  284 	ldw	x, #0x509e
      00815F F6               [ 1]  285 	ld	a, (x)
      008160 AA 10            [ 1]  286 	or	a, #0x10
      008162 F7               [ 1]  287 	ld	(x), a
                                    288 ;	thermo.c: 61: PA_DDR |= MP1;
      008163 AE 50 02         [ 2]  289 	ldw	x, #0x5002
      008166 F6               [ 1]  290 	ld	a, (x)
      008167 AA 04            [ 1]  291 	or	a, #0x04
      008169 F7               [ 1]  292 	ld	(x), a
                                    293 ;	thermo.c: 62: PA_CR1 |= MP1;
      00816A AE 50 03         [ 2]  294 	ldw	x, #0x5003
      00816D F6               [ 1]  295 	ld	a, (x)
      00816E AA 04            [ 1]  296 	or	a, #0x04
      008170 F7               [ 1]  297 	ld	(x), a
                                    298 ;	thermo.c: 64: USART1_CR2 = USART_CR2_TEN | USART_CR2_REN | USART_CR2_RIEN; // Transmit, receive, interrrupt enable
      008171 35 2C 52 35      [ 1]  299 	mov	0x5235+0, #0x2c
                                    300 ;	thermo.c: 65: USART1_CR3 &= ~(USART_CR3_STOP1 | USART_CR3_STOP2); // 1 stop bit
      008175 AE 52 36         [ 2]  301 	ldw	x, #0x5236
      008178 F6               [ 1]  302 	ld	a, (x)
      008179 A4 CF            [ 1]  303 	and	a, #0xcf
      00817B F7               [ 1]  304 	ld	(x), a
                                    305 ;	thermo.c: 66: USART1_BRR1 = 0x11; USART1_BRR2 = 0x6; // 57600 baud (use 8 B for 115200)
      00817C 35 11 52 32      [ 1]  306 	mov	0x5232+0, #0x11
      008180 35 06 52 33      [ 1]  307 	mov	0x5233+0, #0x06
      008184 81               [ 4]  308 	ret
                                    309 ;	thermo.c: 69: int uartWrite(const char *str) {
                                    310 ;	-----------------------------------------
                                    311 ;	 function uartWrite
                                    312 ;	-----------------------------------------
      008185                        313 _uartWrite:
      008185 52 03            [ 2]  314 	sub	sp, #3
                                    315 ;	thermo.c: 71: for(i = 0; i < strlen(str); i++) {
      008187 0F 01            [ 1]  316 	clr	(0x01, sp)
      008189                        317 00106$:
      008189 1E 06            [ 2]  318 	ldw	x, (0x06, sp)
      00818B 89               [ 2]  319 	pushw	x
      00818C CD 83 EC         [ 4]  320 	call	_strlen
      00818F 5B 02            [ 2]  321 	addw	sp, #2
      008191 1F 02            [ 2]  322 	ldw	(0x02, sp), x
      008193 5F               [ 1]  323 	clrw	x
      008194 7B 01            [ 1]  324 	ld	a, (0x01, sp)
      008196 97               [ 1]  325 	ld	xl, a
      008197 13 02            [ 2]  326 	cpw	x, (0x02, sp)
      008199 24 17            [ 1]  327 	jrnc	00104$
                                    328 ;	thermo.c: 72: while(!(USART1_SR & USART_SR_TXE));
      00819B                        329 00101$:
      00819B AE 52 30         [ 2]  330 	ldw	x, #0x5230
      00819E F6               [ 1]  331 	ld	a, (x)
      00819F 4D               [ 1]  332 	tnz	a
      0081A0 2A F9            [ 1]  333 	jrpl	00101$
                                    334 ;	thermo.c: 73: USART1_DR = str[i];
      0081A2 5F               [ 1]  335 	clrw	x
      0081A3 7B 01            [ 1]  336 	ld	a, (0x01, sp)
      0081A5 97               [ 1]  337 	ld	xl, a
      0081A6 72 FB 06         [ 2]  338 	addw	x, (0x06, sp)
      0081A9 F6               [ 1]  339 	ld	a, (x)
      0081AA AE 52 31         [ 2]  340 	ldw	x, #0x5231
      0081AD F7               [ 1]  341 	ld	(x), a
                                    342 ;	thermo.c: 71: for(i = 0; i < strlen(str); i++) {
      0081AE 0C 01            [ 1]  343 	inc	(0x01, sp)
      0081B0 20 D7            [ 2]  344 	jra	00106$
      0081B2                        345 00104$:
                                    346 ;	thermo.c: 75: return(i); // Bytes sent
      0081B2 5F               [ 1]  347 	clrw	x
      0081B3 7B 01            [ 1]  348 	ld	a, (0x01, sp)
      0081B5 97               [ 1]  349 	ld	xl, a
      0081B6 5B 03            [ 2]  350 	addw	sp, #3
      0081B8 81               [ 4]  351 	ret
                                    352 ;	thermo.c: 78: void putchar(unsigned char data) {
                                    353 ;	-----------------------------------------
                                    354 ;	 function putchar
                                    355 ;	-----------------------------------------
      0081B9                        356 _putchar:
                                    357 ;	thermo.c: 79: USART1_DR = data;
      0081B9 AE 52 31         [ 2]  358 	ldw	x, #0x5231
      0081BC 7B 03            [ 1]  359 	ld	a, (0x03, sp)
      0081BE F7               [ 1]  360 	ld	(x), a
                                    361 ;	thermo.c: 80: while (!(USART1_SR & USART_SR_TC));
      0081BF                        362 00101$:
      0081BF AE 52 30         [ 2]  363 	ldw	x, #0x5230
      0081C2 F6               [ 1]  364 	ld	a, (x)
      0081C3 A5 40            [ 1]  365 	bcp	a, #0x40
      0081C5 27 F8            [ 1]  366 	jreq	00101$
      0081C7 81               [ 4]  367 	ret
                                    368 ;	thermo.c: 83: char uartRead() {
                                    369 ;	-----------------------------------------
                                    370 ;	 function uartRead
                                    371 ;	-----------------------------------------
      0081C8                        372 _uartRead:
                                    373 ;	thermo.c: 84: if(USART1_SR & USART_SR_RXNE) {
      0081C8 AE 52 30         [ 2]  374 	ldw	x, #0x5230
      0081CB F6               [ 1]  375 	ld	a, (x)
      0081CC A5 20            [ 1]  376 	bcp	a, #0x20
      0081CE 27 05            [ 1]  377 	jreq	00102$
                                    378 ;	thermo.c: 85: return USART1_DR;
      0081D0 AE 52 31         [ 2]  379 	ldw	x, #0x5231
      0081D3 F6               [ 1]  380 	ld	a, (x)
      0081D4 81               [ 4]  381 	ret
      0081D5                        382 00102$:
                                    383 ;	thermo.c: 87: return '\0';
      0081D5 4F               [ 1]  384 	clr	a
      0081D6 81               [ 4]  385 	ret
                                    386 ;	thermo.c: 91: char* readUartBuffer() {
                                    387 ;	-----------------------------------------
                                    388 ;	 function readUartBuffer
                                    389 ;	-----------------------------------------
      0081D7                        390 _readUartBuffer:
                                    391 ;	thermo.c: 92: uartBufferPos = 0;
      0081D7 72 5F 00 22      [ 1]  392 	clr	_uartBufferPos+0
                                    393 ;	thermo.c: 93: return uartBuffer;
      0081DB AE 00 01         [ 2]  394 	ldw	x, #_uartBuffer+0
      0081DE 81               [ 4]  395 	ret
                                    396 ;	thermo.c: 96: void clearUartBuffer() {
                                    397 ;	-----------------------------------------
                                    398 ;	 function clearUartBuffer
                                    399 ;	-----------------------------------------
      0081DF                        400 _clearUartBuffer:
                                    401 ;	thermo.c: 97: memset(uartBuffer,0,UART_BUFFER_SIZE);
      0081DF AE 00 01         [ 2]  402 	ldw	x, #_uartBuffer+0
      0081E2 4B 20            [ 1]  403 	push	#0x20
      0081E4 4B 00            [ 1]  404 	push	#0x00
      0081E6 4B 00            [ 1]  405 	push	#0x00
      0081E8 4B 00            [ 1]  406 	push	#0x00
      0081EA 89               [ 2]  407 	pushw	x
      0081EB CD 83 9B         [ 4]  408 	call	_memset
      0081EE 5B 06            [ 2]  409 	addw	sp, #6
      0081F0 81               [ 4]  410 	ret
                                    411 ;	thermo.c: 101: void initADC() {
                                    412 ;	-----------------------------------------
                                    413 ;	 function initADC
                                    414 ;	-----------------------------------------
      0081F1                        415 _initADC:
                                    416 ;	thermo.c: 102: ADC1_SQR1 |= ADC1_SQR1_DMAOFF; // disable DMA
      0081F1 72 1E 53 4A      [ 1]  417 	bset	0x534a, #7
                                    418 ;	thermo.c: 103: ADC1_SQR4 |= (1 << 5); // Select ADC 5 (PC3)
      0081F5 AE 53 4D         [ 2]  419 	ldw	x, #0x534d
      0081F8 F6               [ 1]  420 	ld	a, (x)
      0081F9 AA 20            [ 1]  421 	or	a, #0x20
      0081FB F7               [ 1]  422 	ld	(x), a
                                    423 ;	thermo.c: 104: ADC1_CR1 |= ADC1_CR1_ADON; // wake up
      0081FC 72 10 53 40      [ 1]  424 	bset	0x5340, #0
      008200 81               [ 4]  425 	ret
                                    426 ;	thermo.c: 108: uint16_t readADC() {
                                    427 ;	-----------------------------------------
                                    428 ;	 function readADC
                                    429 ;	-----------------------------------------
      008201                        430 _readADC:
      008201 52 06            [ 2]  431 	sub	sp, #6
                                    432 ;	thermo.c: 110: ADC1_CR1 |= ADC1_CR1_START; // start
      008203 AE 53 40         [ 2]  433 	ldw	x, #0x5340
      008206 F6               [ 1]  434 	ld	a, (x)
      008207 AA 02            [ 1]  435 	or	a, #0x02
      008209 F7               [ 1]  436 	ld	(x), a
                                    437 ;	thermo.c: 111: while (!(ADC1_SR & ADC1_SR_EOC));
      00820A                        438 00101$:
      00820A AE 53 43         [ 2]  439 	ldw	x, #0x5343
      00820D F6               [ 1]  440 	ld	a, (x)
      00820E 44               [ 1]  441 	srl	a
      00820F 24 F9            [ 1]  442 	jrnc	00101$
                                    443 ;	thermo.c: 112: adcH = ADC1_DRH;
      008211 AE 53 44         [ 2]  444 	ldw	x, #0x5344
      008214 F6               [ 1]  445 	ld	a, (x)
                                    446 ;	thermo.c: 113: adcL = ADC1_DRL;
      008215 AE 53 45         [ 2]  447 	ldw	x, #0x5345
      008218 88               [ 1]  448 	push	a
      008219 F6               [ 1]  449 	ld	a, (x)
      00821A 97               [ 1]  450 	ld	xl, a
      00821B 84               [ 1]  451 	pop	a
                                    452 ;	thermo.c: 115: return (adcL | (adcH << 8));
      00821C 0F 05            [ 1]  453 	clr	(0x05, sp)
      00821E 0F 04            [ 1]  454 	clr	(0x04, sp)
      008220 0F 01            [ 1]  455 	clr	(0x01, sp)
      008222 1A 01            [ 1]  456 	or	a, (0x01, sp)
      008224 01               [ 1]  457 	rrwa	x
      008225 1A 04            [ 1]  458 	or	a, (0x04, sp)
      008227 97               [ 1]  459 	ld	xl, a
      008228 5B 06            [ 2]  460 	addw	sp, #6
      00822A 81               [ 4]  461 	ret
                                    462 ;	thermo.c: 119: void initClock() {
                                    463 ;	-----------------------------------------
                                    464 ;	 function initClock
                                    465 ;	-----------------------------------------
      00822B                        466 _initClock:
                                    467 ;	thermo.c: 120: CLK_CKDIVR = 0; // Set the frequency to 16 MHz
      00822B 35 00 50 C0      [ 1]  468 	mov	0x50c0+0, #0x00
                                    469 ;	thermo.c: 121: CLK_PCKENR1 = 0xFF; // Enable peripherals
      00822F 35 FF 50 C3      [ 1]  470 	mov	0x50c3+0, #0xff
                                    471 ;	thermo.c: 122: CLK_PCKENR2 = 0xFF;
      008233 35 FF 50 C4      [ 1]  472 	mov	0x50c4+0, #0xff
      008237 81               [ 4]  473 	ret
                                    474 ;	thermo.c: 126: int main() {
                                    475 ;	-----------------------------------------
                                    476 ;	 function main
                                    477 ;	-----------------------------------------
      008238                        478 _main:
      008238 52 02            [ 2]  479 	sub	sp, #2
                                    480 ;	thermo.c: 127: initClock();
      00823A CD 82 2B         [ 4]  481 	call	_initClock
                                    482 ;	thermo.c: 129: enableInterrupts()
      00823D 9A               [ 1]  483 	rim
                                    484 ;	thermo.c: 131: initADC();
      00823E CD 81 F1         [ 4]  485 	call	_initADC
                                    486 ;	thermo.c: 133: initUSART();
      008241 CD 81 5C         [ 4]  487 	call	_initUSART
                                    488 ;	thermo.c: 135: initMotor();
      008244 CD 81 09         [ 4]  489 	call	_initMotor
                                    490 ;	thermo.c: 137: printf("Thermostat: Startup complete\n");
      008247 AE 82 FB         [ 2]  491 	ldw	x, #___str_0+0
      00824A 89               [ 2]  492 	pushw	x
      00824B CD 83 D6         [ 4]  493 	call	_printf
      00824E 5B 02            [ 2]  494 	addw	sp, #2
                                    495 ;	thermo.c: 140: while(true) {
      008250                        496 00104$:
                                    497 ;	thermo.c: 142: count++;
      008250 C6 00 21         [ 1]  498 	ld	a, _count+0
      008253 4C               [ 1]  499 	inc	a
      008254 C7 00 21         [ 1]  500 	ld	_count+0, a
                                    501 ;	thermo.c: 143: delay(1000);
      008257 4B E8            [ 1]  502 	push	#0xe8
      008259 4B 03            [ 1]  503 	push	#0x03
      00825B 5F               [ 1]  504 	clrw	x
      00825C 89               [ 2]  505 	pushw	x
      00825D CD 80 A0         [ 4]  506 	call	_delay
      008260 5B 04            [ 2]  507 	addw	sp, #4
                                    508 ;	thermo.c: 144: printf("Loop start: %d \n", count);
      008262 5F               [ 1]  509 	clrw	x
      008263 C6 00 21         [ 1]  510 	ld	a, _count+0
      008266 97               [ 1]  511 	ld	xl, a
      008267 90 AE 83 19      [ 2]  512 	ldw	y, #___str_1+0
      00826B 89               [ 2]  513 	pushw	x
      00826C 90 89            [ 2]  514 	pushw	y
      00826E CD 83 D6         [ 4]  515 	call	_printf
      008271 5B 04            [ 2]  516 	addw	sp, #4
                                    517 ;	thermo.c: 145: adc = readADC();
      008273 CD 82 01         [ 4]  518 	call	_readADC
      008276 1F 01            [ 2]  519 	ldw	(0x01, sp), x
                                    520 ;	thermo.c: 146: printf("ADC value: %d, %d\n", adc, uartBufferPos);
      008278 5F               [ 1]  521 	clrw	x
      008279 C6 00 22         [ 1]  522 	ld	a, _uartBufferPos+0
      00827C 97               [ 1]  523 	ld	xl, a
      00827D 90 AE 83 2A      [ 2]  524 	ldw	y, #___str_2+0
      008281 89               [ 2]  525 	pushw	x
      008282 1E 03            [ 2]  526 	ldw	x, (0x03, sp)
      008284 89               [ 2]  527 	pushw	x
      008285 90 89            [ 2]  528 	pushw	y
      008287 CD 83 D6         [ 4]  529 	call	_printf
      00828A 5B 06            [ 2]  530 	addw	sp, #6
                                    531 ;	thermo.c: 147: if (adc < 2000)
      00828C 1E 01            [ 2]  532 	ldw	x, (0x01, sp)
      00828E A3 07 D0         [ 2]  533 	cpw	x, #0x07d0
      008291 24 0A            [ 1]  534 	jrnc	00102$
                                    535 ;	thermo.c: 149: dir = !dir;
      008293 C6 00 23         [ 1]  536 	ld	a, _dir+0
      008296 A0 01            [ 1]  537 	sub	a, #0x01
      008298 4F               [ 1]  538 	clr	a
      008299 49               [ 1]  539 	rlc	a
      00829A C7 00 23         [ 1]  540 	ld	_dir+0, a
      00829D                        541 00102$:
                                    542 ;	thermo.c: 151: setMotor(dir, !dir);
      00829D C6 00 23         [ 1]  543 	ld	a, _dir+0
      0082A0 A0 01            [ 1]  544 	sub	a, #0x01
      0082A2 4F               [ 1]  545 	clr	a
      0082A3 49               [ 1]  546 	rlc	a
      0082A4 88               [ 1]  547 	push	a
      0082A5 3B 00 23         [ 1]  548 	push	_dir+0
      0082A8 CD 81 34         [ 4]  549 	call	_setMotor
      0082AB 5B 02            [ 2]  550 	addw	sp, #2
                                    551 ;	thermo.c: 152: printf("%s\n", readUartBuffer());
      0082AD CD 81 D7         [ 4]  552 	call	_readUartBuffer
      0082B0 90 AE 83 3D      [ 2]  553 	ldw	y, #___str_3+0
      0082B4 89               [ 2]  554 	pushw	x
      0082B5 90 89            [ 2]  555 	pushw	y
      0082B7 CD 83 D6         [ 4]  556 	call	_printf
      0082BA 5B 04            [ 2]  557 	addw	sp, #4
                                    558 ;	thermo.c: 153: clearUartBuffer();
      0082BC CD 81 DF         [ 4]  559 	call	_clearUartBuffer
      0082BF 20 8F            [ 2]  560 	jra	00104$
      0082C1 5B 02            [ 2]  561 	addw	sp, #2
      0082C3 81               [ 4]  562 	ret
                                    563 ;	thermo.c: 162: void uart_isr() __interrupt(UART_RECV_ISR) {
                                    564 ;	-----------------------------------------
                                    565 ;	 function uart_isr
                                    566 ;	-----------------------------------------
      0082C4                        567 _uart_isr:
      0082C4 4F               [ 1]  568 	clr	a
      0082C5 62               [ 2]  569 	div	x, a
      0082C6 52 03            [ 2]  570 	sub	sp, #3
                                    571 ;	thermo.c: 164: uartBufferPos %= UART_BUFFER_SIZE-1;
      0082C8 5F               [ 1]  572 	clrw	x
      0082C9 C6 00 22         [ 1]  573 	ld	a, _uartBufferPos+0
      0082CC 97               [ 1]  574 	ld	xl, a
      0082CD A6 1F            [ 1]  575 	ld	a, #0x1f
      0082CF 62               [ 2]  576 	div	x, a
                                    577 ;	thermo.c: 165: for(i = uartBufferPos; i < UART_BUFFER_SIZE; i++) {
      0082D0 C7 00 22         [ 1]  578 	ld	_uartBufferPos+0, a
      0082D3 AE 00 01         [ 2]  579 	ldw	x, #_uartBuffer+0
      0082D6 1F 02            [ 2]  580 	ldw	(0x02, sp), x
      0082D8 6B 01            [ 1]  581 	ld	(0x01, sp), a
      0082DA                        582 00103$:
      0082DA 7B 01            [ 1]  583 	ld	a, (0x01, sp)
      0082DC A1 20            [ 1]  584 	cp	a, #0x20
      0082DE 24 11            [ 1]  585 	jrnc	00101$
                                    586 ;	thermo.c: 166: uartBuffer[i] = uartRead();
      0082E0 5F               [ 1]  587 	clrw	x
      0082E1 7B 01            [ 1]  588 	ld	a, (0x01, sp)
      0082E3 97               [ 1]  589 	ld	xl, a
      0082E4 72 FB 02         [ 2]  590 	addw	x, (0x02, sp)
      0082E7 89               [ 2]  591 	pushw	x
      0082E8 CD 81 C8         [ 4]  592 	call	_uartRead
      0082EB 85               [ 2]  593 	popw	x
      0082EC F7               [ 1]  594 	ld	(x), a
                                    595 ;	thermo.c: 165: for(i = uartBufferPos; i < UART_BUFFER_SIZE; i++) {
      0082ED 0C 01            [ 1]  596 	inc	(0x01, sp)
      0082EF 20 E9            [ 2]  597 	jra	00103$
      0082F1                        598 00101$:
                                    599 ;	thermo.c: 168: uartBufferPos++;
      0082F1 C6 00 22         [ 1]  600 	ld	a, _uartBufferPos+0
      0082F4 4C               [ 1]  601 	inc	a
      0082F5 C7 00 22         [ 1]  602 	ld	_uartBufferPos+0, a
      0082F8 5B 03            [ 2]  603 	addw	sp, #3
      0082FA 80               [11]  604 	iret
                                    605 	.area CODE
      0082FB                        606 ___str_0:
      0082FB 54 68 65 72 6D 6F 73   607 	.ascii "Thermostat: Startup complete"
             74 61 74 3A 20 53 74
             61 72 74 75 70 20 63
             6F 6D 70 6C 65 74 65
      008317 0A                     608 	.db 0x0a
      008318 00                     609 	.db 0x00
      008319                        610 ___str_1:
      008319 4C 6F 6F 70 20 73 74   611 	.ascii "Loop start: %d "
             61 72 74 3A 20 25 64
             20
      008328 0A                     612 	.db 0x0a
      008329 00                     613 	.db 0x00
      00832A                        614 ___str_2:
      00832A 41 44 43 20 76 61 6C   615 	.ascii "ADC value: %d, %d"
             75 65 3A 20 25 64 2C
             20 25 64
      00833B 0A                     616 	.db 0x0a
      00833C 00                     617 	.db 0x00
      00833D                        618 ___str_3:
      00833D 25 73                  619 	.ascii "%s"
      00833F 0A                     620 	.db 0x0a
      008340 00                     621 	.db 0x00
                                    622 	.area INITIALIZER
      008BB4                        623 __xinit__count:
      008BB4 00                     624 	.db #0x00	; 0
      008BB5                        625 __xinit__uartBufferPos:
      008BB5 00                     626 	.db #0x00	; 0
      008BB6                        627 __xinit__dir:
      008BB6 00                     628 	.db #0x00	;  0
                                    629 	.area CABS (ABS)
