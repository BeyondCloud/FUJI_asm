  mov $1,%eax
  mov $2,%ebx
  mov $3,%ecx
  mov $4,%edx

  movl $5, ebx 
  add %eax, %ebx
  add %ebx, %ecx
  add %ecx, %edx
  sub %eax, %ebx
  sub %ebx, %ecx
  sub %ecx, %edx
  jmp L1
  ja L1
  jae L2

  jae L1
  jb L1
  jbe L1
  jc L1
  je L1
  jg L1
  jge L1
  jl L1
  jle L1
  L2:
  mul %eax
  mul %ebx
  mul %ecx
  
  div %eax
  div %ebx
  div %ecx
  
    
  cmp  %eax, %ebx
  cmpl	$1, %eax
movl	$500, 24(%esp)
movl	$500, 24(%esp)
movl	$500, 24(%esp)
movl	$500, 24(%esp)
movl	$500, 24(%esp)
movl	$500, 24(%esp)
movl	$500, 24(%esp)
movl	$500, 24(%esp)
movl	$500, 24(%esp)
movl	$500, 24(%esp)

L1:
