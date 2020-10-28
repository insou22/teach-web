main:

loop1_init:
	li		$t0, 0		# t0 = row

loop1_cond:
	blt		$t0, 6, loop1_body	# row < 6
	b		loop1_end

loop1_body:

loop2_init:
	li		$t1, 0		# t1 = col

loop2_cond:
	blt		$t1, 12, loop2_body	# col < 12
	b		loop2_end

loop2_body:
	mul		$t2, $t0, 12	# 12 * row
	add		$t2, $t2, $t1	# (12 * row) + col
	lb		$a0, flag($t2)
	li		$v0, 11			# syscall 11 = print_char
	syscall

loop2_step:
	addi	$t1, $t1, 1	# col++
	b		loop2_cond

loop2_end:
	li		$v0, 11		# syscall 11 = print_char
	li		$a0, '\n'
	syscall

loop1_step:
	addi	$t0, $t0, 1	# row++
	b		loop1_cond

loop1_end:

	li		$v0, 0
	jr		$ra


	.data
flag:
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
	.byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
    .byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
