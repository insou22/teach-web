	.data
enter_num_str: .asciiz "Enter your n: "

	.text

main:
main__pro:	# Main's prologue
	# ra, fp, (no saved registers) 2 * 4 = 8

	addiu	$sp, $sp, -8

	sw		$fp, 4($sp)
	sw		$ra,  ($sp)

	addiu	$fp, $sp, 8

main__begin:	# Main's body
	li		$v0, 4	# print string
	la		$a0, enter_num_str
	syscall

	li		$v0, 5	# read int
	syscall

	move	$a0, $v0	# first argument

	jal fib

	move	$a0, $v0
	li		$v0, 1 # print int
	syscall

main__epi:	# Main's epilogue

	addiu	$sp, $fp, -8

	lw		$ra,  ($sp)
	lw		$fp, 4($sp)

	addiu	$sp, $sp, 8

	jr $ra



fib:
fib__pro:
    # ra, fp, s0, s1, s2, s3	6 * 4 = 24

	# build stack frame

    addiu   $sp, $sp, -24

    sw      $fp, 20($sp)
    sw      $ra, 16($sp)
	sw		$s0, 12($sp)
	sw		$s1,  8($sp)
	sw		$s2,  4($sp)
	sw		$s3,   ($sp)

    addiu   $fp, $sp, 24


fib__begin:
	ble		$a0, 1 fib_return_n
	j		fib_calc

fib_return_n:
	move	$v0, $a0
	j		fib__epi

fib_calc:
	addi	$s0, $a0, -1	# n - 1
	addi	$s1, $a0, -2	# n - 2

	# fib(n - 1)
	move	$a0, $s0
	jal		fib

	move	$s2, $v0	# s2 = fib(n - 1)


	# fib (n - 2)
	move	$a0, $s1
	jal		fib

	move	$s3, $v0	# s3 = fib(n - 2)

	add		$v0, $s2, $s3	# return val = fib(n - 1) + fib(n - 2)

fib__epi:

	# teardown stack frame

    addiu   $sp, $fp, -24

	lw		$s3,   ($sp)
	lw		$s2,  4($sp)
	lw		$s1,  8($sp)
	lw		$s0, 12($sp)
    lw      $ra, 16($sp)
    lw      $fp, 20($sp)

    addiu   $sp, $sp, 24

	jr		$ra		# return
