.data
x:	.word 0
s:	.word 0
m:	.word 0
z:	.word 0
y:	.word 0
newLine:	.asciiz "
" 

.text
main:
li $t0,0
move $t0,$t0
sw $t0,x
li $t0,0
move $t0,$t0
sw $t0,s
sw $fp,0($sp)
addiu $sp,$sp,-4
li $t0,3
move $a0,$t0
lw $t0,x
move $a1,$t0
add $t3,$a0,$a1
move $s7,$t3
sw $t0,0($sp)
addiu $sp,$sp,-4
li $t0,100
sw $t0,0($sp)
addiu $sp,$sp,-4
jal r
sw $v1,m
j exit
r:
move $fp,$sp
sw $ra,0($sp)
addiu $sp,$sp,-4
lw $t0,4($fp)
sw $t0,y
lw $t0,8($fp)
sw $t0,z
lw $t0,z
move $t0,$t0
sw $t0,x
L3:
lw $t0,x
move $a2,$t0
lw $t0,y
move $a3,$t0
slt $t3,$a2,$a3
move $s7,$t3
li $t5,1
beq $s7, $t5 , L1
j L2
L1:
lw $t0,s
move $a0,$t0
lw $t0,x
move $a1,$t0
add $t3,$a0,$a1
move $s7,$t3
move $t0,$s7
sw $t0,s
lw $t0,x
move $a0,$t0
li $t0,2
move $a1,$t0
add $t3,$a0,$a1
move $s7,$t3
move $t0,$s7
sw $t0,x

    
   
j L3
L2:
lw $t0,s
lw $ra, 4($sp)
addi $sp,$sp,16
move $v1,$t0
jr $ra

exit:
la $a0,newLine
li $v0, 4
syscall
li  $v0, 1
lw $t0,x
add $a0, $t0, $zero
syscall
la $a0,newLine
li $v0, 4
syscall
la $a0,newLine
li $v0, 4
syscall
li  $v0, 1
lw $t0,s
add $a0, $t0, $zero
syscall
la $a0,newLine
li $v0, 4
syscall
la $a0,newLine
li $v0, 4
syscall
li  $v0, 1
lw $t0,m
add $a0, $t0, $zero
syscall
la $a0,newLine
li $v0, 4
syscall
la $a0,newLine
li $v0, 4
syscall
li  $v0, 1
lw $t0,z
add $a0, $t0, $zero
syscall
la $a0,newLine
li $v0, 4
syscall
la $a0,newLine
li $v0, 4
syscall
li  $v0, 1
lw $t0,y
add $a0, $t0, $zero
syscall
la $a0,newLine
li $v0, 4
syscall
li  $v0, 1
lw $t0,m
add $a0, $t0, $zero
syscall
la $a0,newLine
li $v0, 4
syscall
li $v0, 10
syscall
