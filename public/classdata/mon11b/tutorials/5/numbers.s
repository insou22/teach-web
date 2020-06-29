    .data
numbers: .word 0 0 0 0 0 0 0 0 0 0


    .text
main:
    li      $t0, 0  # t0 = i = 0

main_while_cond:
    blt     $t0, 10, main_while_body    # if (i < 10)
    j       main_while_end

main_while_body:
    li      $v0, 5  # 5 = read_int
    syscall

    li      $t1, 4  # 4 bytes for word
    mul     $t1, $t0, $t1   # t1 = 4 * i
    sw      $v0, numbers($t1)   # numbers[i] = input

    addi    $t0, $t0, 1     # i++

    j       main_while_cond

main_while_end:
    jr      $ra