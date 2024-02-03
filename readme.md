<!-- Prefix Evaluation -->

*+-/*326414

1. Iterate through the end of string
2. Check if the string char is a number or an operator. Make the char a number by using ascii and then push.
   If it's an operator pop top two numbers from stack and perform the operation using switch cases and push the result.
3. If the string ends then just display the result you got.

<!-- Postfix evaluation -->

1. Iterate through the end of string
2. Check if the string

<!-- Infix to prefix -->

1. If operand print it
2. If '(' then push on to stack
3. If operator, check precedence and if the precedence is higher than the top, push it else pop out the

<!-- Infix to postfix -->

1. If operand print it
2. If '(' then push onto stack
3. If operator, check precendence and if the precedence is higher than the top, push it else pop until the stack becomes empty ir the top element gas kess precedence.
4. If ')' then check the top od the stack and keep poppinf it unless you don't encounter '('. pop out the ( and repeat the process.
   Once you reach at the end of the string pop out everything from the stack.
   Examples:
   Infix: (a+b)/((c*d)-e) || postfix: ab+cd*e-/
   Infix: (a-b)/(c+d)-e || postfix: ab-cd+\*e-
   Infix: (a/b)/(c+d)-(e+f) || postfix: ab/cd+ef+-/

<!-- Infix to prefix -->

Example: (a-b/c)\*(a/k-l)

1. Reverse the string
2. Convert the ')' to '('and vice versa (l-k/a)\*(c/b-a)
3. Repeat the algo for postfix
4. Reverse the answer.

<!-- Queue using stacks (Expensive approach -> enqueue)-->

Use two stacks

1. Empty all elements from s1 to s2
2. Push the new element to s1
3. Pop each element from s2 and push it into s1
4. To print or dequeue, pop out every element from s1

<!-- Queue using stacks (Expensive approach -> dequeue)  -->

Use two empty stacks

1. Pop all the elements from s1 and push it in s2
2. Pop all the elements from s2
