    .data
numbers: .word 0 1 2 -3 4 -5 6 -7 8 9


    .text
main:
    li      $t0, 0  # t0 = i = 0

main_while_cond:
    blt     $t0, 10, main_while_body    # if (i < 10)
    j       main_while_end

main_while_body:
    li      $t1, 4  # 4 bytes for word
    mul     $t1, $t0, $t1   # t1 = 4 * i

    lw      $t2, numbers($t1)
    blt     $t2, $zero, main_if_true
    j       main_if_false

main_if_true:
    addi    $t2, $t2, 42
    sw      $t2, numbers($t1)
    j       main_if_end

main_if_false:
    j       main_if_end

main_if_end:
    addi    $t0, $t0, 1     # i++

    j       main_while_cond

main_while_end:
    jr      $ra