# push_swap
Attempt at making a sorting algorithm.

Can sort a set of numbers from small to big.
Uses a predetermined set of usable operations on two stacks:
Rotating (or reverse rotating) a stack (by 1).

Pushing 1 number from one stack to the other.

Swapping the number at the top of a stack with the one under it. 

Program can be used by passing list of numbers as argument, it will then display
all the neccesary operations to properly sort it.

e.g. ./push_swap "1 3 2 4"

Amount of operations used easily found by running:
./push_swap "1 2 4 3" | wc -l
