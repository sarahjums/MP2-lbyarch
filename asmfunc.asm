section .text
bits 64
default rel

global dot_prod_asm

dot_prod_asm:
	xorpd xmm5, xmm5 ; count - initially 0
loop:
	movsd xmm3, [rcx]
	movsd xmm4, [rdx]
	mulsd xmm3, xmm4
	addsd xmm5, xmm3
	add rcx, 8
	add rdx, 8

	dec r8
	jz loop_end
	jmp loop

loop_end:
	movsd xmm0, xmm5
    ret
