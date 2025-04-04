
Expr_Eval : str_stack.c int_stack.c infix_to_postfix.c postfix_evaluation.c main.c
	gcc -c str_stack.c
	gcc -c int_stack.c
	gcc -c infix_to_postfix.c
	gcc -c postfix_evaluation.c
	gcc -c main.c
	gcc -o Expr_Eval str_stack.o int_stack.o infix_to_postfix.o postfix_evaluation.o main.o

