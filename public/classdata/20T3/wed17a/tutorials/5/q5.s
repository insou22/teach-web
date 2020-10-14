	.data
numbers: .word 0 0 0 0 0 0 0 0 0 0 0 

	.text

main:
	li		$t0, 0	# int i = 0;

main_loop_cond:
	blt		$t0, 10, main_loop_body
	b		main_loop_end

main_loop_body:
	la		$t1, numbers  # $t1 = base_addr numbers
	mul		$t2, $t0, 4   # $t2 = i * 4
	
	add		$t1, $t1, $t2 # $t1 = &numbers[i]
	
	li		$v0, 5
	syscall

	move	$t2, $v0
	sw		$t2, ($t1)

	# scanf("%d", &numbers[i]);
	
	addiu	$t0, $t0, 1	# i++;
	b		main_loop_cond

main_loop_end:
	li		$v0, 0
	jr		$ra
