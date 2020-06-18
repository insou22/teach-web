
0x0013
0000 0000 0001 0011 -> 19

0x0444
0000 0100 0100 0100 -> 4 + 64 + 1024 = 1092

0x1234
0001 0010 0011 0100 -> 4 + 16 + 32 + 512 + 4096 = 4660

0xffff
1111 1111 1111 1111 -> first bit is a 1!!! do the thing!
                    -> step 1: remember that the number is negative
0000 0000 0000 0000 -> step 2: flip all the bits
0000 0000 0000 0001 -> step 3: add 1
                    -> DONE!
                        -> Number is 1
                        -> Number is negative
                        -> Therefore: -1

0x8000
1000 0000 0000 0000 -> step 1: num is negative
0111 1111 1111 1111 -> step 2: flip all the bits
1000 0000 0000 0000 -> step 3: add 1!
                    -> DONE!
                        -> Number is BIG
                        -> Number is negative
                        -> Therefore: -32768


100
0000 0000 0110 0100 -> 100 in binary
0x0064

-5
0000 0000 0000 0101 -> step 1: num is negative
1111 1111 1111 1010 -> step 2: flip all the bits
1111 1111 1111 1011 -> step 3: add 1

-100
0000 0000 0110 0100 -> step 1
1111 1111 1001 1011 -> step 2
1111 1111 1001 1100 -> step 3


  100 + (-100) == 0
  0000 0000 0110 0100 =  100
  1111 1111 1001 1100 = -100
1 0000 0000 0000 0000 -> special rule for arithmetic: discard the extra bit on the left
  0000 0000 0000 0000 = 0