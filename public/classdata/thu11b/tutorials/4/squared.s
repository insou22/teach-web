    .data
enter_number_str: .asciiz "Enter a number: "

    .text
main:
    # print "Enter a number: "
    li      $v0, 4
    la      $a0, enter_number_str
    syscall

    # read int input
    li      $v0, 5
    syscall

    # x = t0, y = t1 = x * x
    move    $t0, $v0
    mul     $t1, $t0, $t0

    # print y
    li      $v0, 1
    move    $a0, $t1
    syscall

    # print newline
    li      $v0, 11
    li      $a0, 10 # '\n'
    syscall

    # return
    jr      $ra