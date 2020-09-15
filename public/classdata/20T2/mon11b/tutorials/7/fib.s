	.data
enter_n_str: .asciiz "Enter n: "
print_the_str: .asciiz "The "
print_fib_str: .asciiz "'th fibonacci number is "
print_end_str: .asciiz ".\n"

	.text
main:

main__pro:
addi	$sp, $sp, -8
sw		$ra,  ($sp)
sw		$s0, 4($sp)

li		$v0, 4
la		$a0, enter_n_str
syscall

li		$v0, 5
syscall

move	$s0, $v0	# store nth in $s0

# call fib(nth);

move	$a0, $s0
jal		fib
move	$t1, $v0	# store fib(nth) in $t1


li		$v0, 4
la		$a0, print_the_str 
syscall

li		$v0, 1
move	$a0, $s0
syscall

li		$v0, 4
la		$a0, print_fib_str
syscall

li		$v0, 1
move	$a0, $t1
syscall

li		$v0, 4
la		$a0, print_end_str
syscall

main__epi:
lw		$s0, 4($sp)
lw		$ra,  ($sp)
addi	$sp, $sp, 8

li		$v0, 0	# return 0
jr		$ra




fib:

fib__pro:
# stack frame!!
addi	$sp, $sp, -16
sw		$ra,   ($sp)
sw		$s0,  4($sp) 
sw		$s1,  8($sp)
sw		$s2, 12($sp)

move	$s0, $a0	# move nth into $s0

ble		$s0, 1, fib__n_le_1
j		fib__false

fib__n_le_1:
move	$v0, $s0
j		fib__epi	# return nth;

fib__false:

addi	$a0, $s0, -1
jal		fib
move	$s1, $v0

addi	$a0, $s0, -2
jal		fib
move	$s2, $v0

add		$v0, $s1, $s2

fib__epi:
lw		$s2, 12($sp)
lw		$s1,  8($sp)
lw		$s0,  4($sp)
lw		$ra,   ($sp)
addi	$sp, $sp, 16

jr		$ra












