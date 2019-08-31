	.file	"remove-extra-spaces.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -8(%rbp)
	jmp	.L2
.L4:
	cmpl	$32, -8(%rbp)
	jne	.L3
	cmpl	$32, -4(%rbp)
	jne	.L3
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
.L2:
	call	getchar@PLT
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L4
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 9.1.0"
	.section	.note.GNU-stack,"",@progbits
