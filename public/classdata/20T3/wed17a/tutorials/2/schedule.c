1. When should the types in stdint.h be used
2. Show what the following decimal values look like in 8-bit binary, and 2-digit hexadecimal?
.-----------.------------.-------------.
|  decimal  |   binary   | hexadecimal | 
.-----------|------------|-------------|
|     1     | 0b00000001 |     0x01    |
|     8     | 0b00001000 |     0x08    |
|    10     | 0b00001010 |     0x0A    |
|    15     | 0b00001111 |     0x0F    |
|    16     | 0b00010000 |     0x10    |
|    100    | 0b01100100 |     0x64	   |
|    127    | 0b01111111 |     0x7F    |
|    200    | 0b11001000 |     0xC8    |
.-----------.------------.-------------.

3. What are the values of the following expressions:
uint16_t a = 0x5555, b = 0xAAAA, c = 0x0001

.--------------.----------.
|  expression  |   value  |
.--------------.----------.
|    a | b     |  0xFFFF  |
|    a & b     |  0x0000  |
|    a ^ b     |  0xFFFF  |
|    a & ~b    |  0x5555  |
|    c << 6    |  0x0040  |
|    a >> 4    |  0x0555  |
| a & (b << 1) |  0x0000  |
|    b | c     |  0x0000  |
|    a & ~c    |  0x0000  |
.--------------.----------.

4. 👏 Lab 👏 Exercise 👏 Review 👏

>> sixteen_out.c
>> what is a BCD (/ packed BCD) ????
>> ps3 ?


5. Write a function which reverses the order of bits in a given number!

>> reverse_bits.c


6. reverse_quads.c ???


