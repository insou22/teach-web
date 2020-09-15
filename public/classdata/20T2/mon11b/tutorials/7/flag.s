	.data
ROWS = 6
COLS = 12

flag:
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
    .byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'


	.text
main:

	li		$t0, 0	# int row = 0; ($t0)

main_row_cond:

	bge		$t0, ROWS, main_row_end	# while (rows < ROWS) {

	li		$t1, 0	# int col = 0; ($t1)

main_col_cond:

	bge		$t1, COLS, main_col_end # while (cols < COLS) {

	mul		$t2, $t0, COLS	# (row * COLS)
	add		$t2, $t2, $t1	# (row * COLS) + col
	la		$t3, flag		# t3 = addr flag
	add		$t2, $t2, $t3	# flag[(row * COLS) + col]

	lb		$a0, ($t2)		# a0 = flag[(row * COLS) + col]
	li		$v0, 11
	syscall				# printf("%c", ...);

	addi	$t1, $t1, 1			# col++
	j		main_col_cond	# }

main_col_end:
	li		$a0, '\n'
	li		$v0, 11
	syscall					# printf("\n");

	addi	$t0, $t0, 1		# row++;
	j		main_row_cond # }

main_row_end:

	li		$v0, 1
	jr		$ra		# return 0;


