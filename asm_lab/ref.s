.data
NBRS:	.byte	1		# NBRS

.text
.globl _start			# Make start symbol visible
_start:
	movl	$6, %eax

	addl	NBRS,%eax	# (NBRS) + 5
	pushl	NBRS		# push the first dword on the stack (arg to exit)
	call	exit
