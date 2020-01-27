# Quadratic Equation Solver
This C script is intended to solve quadratic sequences by getting the formula for the Nth term.

# Method
* Find the second difference (difference between the differences) in the sequence
* Divide it by two
* Sub it into Xn(squared)
* Subtract these values from the original terms of the sequence
* Solve the values got from the subtraction as a linear sequences
* Add half the second difference squared to this equation

# Example Usage
```console
$ ./a.out 1 3 9 19
1 3 9 19
The second difference is: 4
4 divided by 2 = 2
Thus 2n(squared)
|2n(squared)	|Sequence	|Difference	|
|2		|1		|-1		|
|8		|3		|-5		|
|18		|9		|-9		|
|32		|19		|-13		|

Thus: -1, -5, -9, -13,
Difference: -4
Tn=-4n+3
Tn=2n(squared)-4n+3
```
