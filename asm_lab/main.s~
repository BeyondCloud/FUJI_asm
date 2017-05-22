	.file	"main.cpp"
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$30, 28(%esp)
	movl	$500, 24(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Z5Inputii
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.globl	__Z5Inputii
	.def	__Z5Inputii;	.scl	2;	.type	32;	.endef
__Z5Inputii:
LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$3, -4(%ebp)
	movl	-4(%ebp), %eax
	cmpl	$2, %eax
	je	L5
	cmpl	$2, %eax
	jg	L6
	cmpl	$1, %eax
	je	L7
	jmp	L4
L6:
	cmpl	$3, %eax
	je	L8
	cmpl	$4, %eax
	je	L9
	jmp	L4
L7:
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	jmp	L3
L5:
	movl	8(%ebp), %eax
	subl	12(%ebp), %eax
	jmp	L3
L8:
	movl	8(%ebp), %eax
	imull	12(%ebp), %eax
	jmp	L3
L9:
	movl	8(%ebp), %eax
	cltd
	idivl	12(%ebp)
	jmp	L3
L4:
L3:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1:
	.ident	"GCC: (GNU) 4.9.3"
