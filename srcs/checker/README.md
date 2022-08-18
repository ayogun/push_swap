# Checker

The ```checker``` program reads a random list of integers from the stdin, stores them, and checks to see
if they are sorted. <br />

## How does it work?

Checker program run the sorting algorithm. Sorting algorithm prints out a serial of operations with following a new line character.

The checker program reads the outputs with thanks to get_next_line function. After reading each of operations, one by one, it applies same operations to the stacks. At the end, it checks if the stacks are in desired state. Which means it checks if the stack is sorted. 