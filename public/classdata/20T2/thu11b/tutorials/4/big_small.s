    .data
enter_number_str: .asciiz "Enter a number: "
medium_str: .asciiz "medium"
small_big_str: .asciiz "small/big"

    .text
main:
    # print "Enter a number: "
    li      $v0, 4
    la      $a0, enter_number_str
    syscall

    # read int input
    li      $v0, 5
    syscall

    # x = t0
    move    $t0, $v0
    
    li      $t1, 100
    li      $t2, 1000

    # t3 = x > 100
    sgt     $t3, $t0, $t1
    # t4 = x < 1000
    slt     $t4, $t0, $t2

    # t1 = t3 & t4
    and     $t1, $t3, $t4

    bnez    $t1, if_true # if true
    j       if_false     # if false

if_true:
    # print "Enter a number: "
    li      $v0, 4
    la      $a0, medium_str
    syscall

    j end


if_false:
    # print "Enter a number: "
    li      $v0, 4
    la      $a0, small_big_str
    syscall
    
    j end   # not needed

end:
    # print newline
    li      $v0, 11
    li      $a0, 10 # '\n'
    syscall

    # return
    jr      $ra