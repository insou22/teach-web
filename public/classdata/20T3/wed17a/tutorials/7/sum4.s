main:
	addi	$sp, $sp, -4
	sw		$ra, 0($sp)

	li		$a0, 11
	li		$a1, 13
	li		$a2, 17
	li		$a3, 19
	jal		sum4

	move	$a0, $v0
	li		$v0, 1		# syscall 1 = print_int
	syscall

	li		$a0, '\n'
	li		$v0, 11		# syscall 11 = print_char
	syscall

	lw		$ra, 0($sp)
	addi	$sp, $sp, 4

	li		$v0, 0
	jr		$ra


# === FUNCTION sum4 ===
# arg 0: int a in $a0
# arg 1: int b in $a1
# arg 2: int c in $a2
# arg 3: int d in $a3
# returns int in  $v0
sum4:
	addi	$sp, $sp, -16
	sw		$s2, 12($sp)
	sw		$s1,  8($sp)
	sw		$s0,  4($sp)
	sw		$ra,  0($sp)

	move	$s0, $a2	# c in s0
	move	$s1, $a3	# d in s1

	jal		sum2
	move	$s2, $v0	# e in s2

	move	$a0, $s0
	move	$a1, $s1
	jal		sum2

	move	$a0, $s2
	move	$a1, $v0	# f in v0
	jal		sum2

	lw		$ra,  0($sp)
	lw		$s0,  4($sp)
	lw		$s1,  8($sp)
	lw		$s2, 12($sp)
	addi	$sp, $sp, 16

	jr		$ra


# === FUNCTION sum2 ===
# arg 0: int x in $a0
# arg 1: int y in $a1
# returns int in  $v0
sum2:
	add		$v0, $a0, $a1
	jr		$ra
