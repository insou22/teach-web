    .data
enter_number_str: .asciiz "Enter a number: "

    .globl main

    .text

main:
    li      $v0, 4      # syscall 4 = print string
    la      $a0, enter_number_str
    syscall

    li      $v0, 5      # syscall 5 = read int
    syscall

    move    $t0, $v0    # $t0 = x = input

    mul     $t1, $t0, $t0  # $t1 = y = x * x

    li      $v0, 1      # syscall 1 = print int
    move    $a0, $t1
    syscall

    li      $v0, 11     # syscall 11 = print char
    li      $a0, 10     # TODO: change to '\n'
    syscall

    li      $v0, 0      # return 0;
    jr      $ra