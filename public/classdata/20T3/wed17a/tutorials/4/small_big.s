	.data

prompt_str: .asciiz "Enter a number: "
medium_str: .asciiz "medium\n"
small_big_str: .asciiz "small/big\n"


	.text
main:
	li		$v0, 4 # print string
	la		$a0, prompt_str
	syscall

	li		$v0, 5 # read int
	syscall
	move	$t0, $v0 # x is in $t0

	li		$t1, 100
	sgt		$t2, $t0, $t1 # $t2 = x < 100

	li		$t1, 1000
	slt		$t3, $t0, $t1 # $t3 = x < 1000

	and		$t1, $t2, $t3 # $t1 = (x < 100) && (x < 1000)

	bne		$t1, $zero, if_true
	j		if_false

if_true:
	la		$a0, medium_str
	j		if_finish

if_false:
	la		$a0, small_big_str
	j		if_finish


if_finish:
	li		$v0, 4 # print string
	syscall

	li		$v0, 0
	jr		$ra

