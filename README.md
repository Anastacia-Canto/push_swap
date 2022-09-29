# push_swap

<img src="https://img.shields.io/badge/Structure-Stacks-EE882C"> <img src="https://img.shields.io/badge/Skill-Sorting_Algorithms-EE882C">

This is a challenge to implement an algorithm to sort numbers in ascendent order. To do this you have 2 stacks, one with random numbers and other empty. But... Of course it couldn't be so simple. The stacks have limited allowed operations and you have to sort it with the smallest number of moves. The operations are:

 - sa (swap a): Swap the first 2 elements at the top of stack a.
 Do nothing if there is only one or no elements.
 - sb (swap b): Swap the first 2 elements at the top of stack b.
 Do nothing if there is only one or no elements.
 - ss : sa and sb at the same time.
 - pa (push a): Take the first element at the top of b and put it at the top of a.
 Do nothing if b is empty.
 - pb (push b): Take the first element at the top of a and put it at the top of b.
 Do nothing if a is empty.
 - ra (rotate a): Shift up all elements of stack a by 1.
 The first element becomes the last one.
 - rb (rotate b): Shift up all elements of stack b by 1.
 The first element becomes the last one.
 - rr : ra and rb at the same time.
 - rra (reverse rotate a): Shift down all elements of stack a by 1.
 The last element becomes the first one.
 - rrb (reverse rotate b): Shift down all elements of stack b by 1.
 The last element becomes the first one.
 - rrr : rra and rrb at the same time.

If the numbers are already sorted, the program makes nothing. Also if it receives only one number.

To solve this, I've used the chunks algorithm that seek for numbers by intervals (chunks), push them to stack_b, sort them and give them back to stack_a. You can learn more from this approach on this [article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) from Jamie Dawson.

During implementation and evaluation of this project, I've used the [tester](https://github.com/laisarena/push_swap_tester) from Lais Arena.

To run this program:

```
git clone https://github.com/Anastacia-Canto/push_swap.git
make
./push_swap <ramdom numbers>
