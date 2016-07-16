bits    32

section         .text
	align   4
	dd      0x1BADB002
	dd      0x00
	dd      - (0x1BADB002+0x00)

	
; Calling C kern_main function
global start
extern kern_main
start:
	call kern_main
	cli
	hlt

	
; Global Descriptor Table
global gdt_reload_sr
extern gdt

gdt_reload_sr:
	lgdt [gdt]
	jmp   0x08		; 0x08 = code selector
	mov   AX, 0x10	; 0x10 = data selector
	mov   DS, AX
	mov   ES, AX
	mov   FS, AX
	mov   GS, AX
	mov   SS, AX
	ret
