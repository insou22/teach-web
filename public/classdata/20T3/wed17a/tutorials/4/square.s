	.data

prompt_str: .asciiz "Enter a number: "

	.text
main:
	li		$v0, 4	# syscall 4 = print_string
	la		$a0, prompt_str
	syscall

	li		$v0, 5	# syscall 5 = read_int
	syscall

	move	$t0, $v0
	mul		$t1, $t0, $t0

	li		$v0, 1	# syscall 1 = print_int
	move	$a0, $t1
	syscall

	li		$v0, 11	# syscall 11 = print_char
	li		$a0, '\n'
	syscall

	li		$v0, 0
	jr		$ra

