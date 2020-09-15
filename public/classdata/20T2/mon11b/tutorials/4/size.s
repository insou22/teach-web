    .data
enter_number_str:   .asciiz "Enter a number: "
medium_str:         .asciiz "medium\n"
small_big_str:      .asciiz "small/big\n"

    .globl main

    .text

main:
    li      $v0, 4      # syscall 4 = print string
    la      $a0, enter_number_str
    syscall

    li      $v0, 5      # syscall 5 = read int
    syscall

    move    $t0, $v0    # $t0 = x = input
    
    sgt     $t1, $t0, 100   # $t1 = x > 100
    slt     $t2, $t0, 1000  # $t2 = x < 1000

    and     $t1, $t1, $t2   # $t1 = $t1 & $t2 = (x > 100) & (x < 1000)

    beqz    $t1, if_false

if_true:
    li      $v0, 4      # syscall 4 = print string
    la      $a0, medium_str
    syscall             # printf("medium\n")

    j       finish

if_false:
    li      $v0, 4      # syscall 4 = print string
    la      $a0, small_big_str
    syscall             # printf("small/big\n")

finish:
    li      $v0, 0      # return 0;
    jr      $ra
