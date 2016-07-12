bits    32

section         .text
        align   4
        dd      0x1BADB002
        dd      0x00
        dd      - (0x1BADB002+0x00)

global start
extern kern_main
start:
        call kern_main
		cli
        hlt