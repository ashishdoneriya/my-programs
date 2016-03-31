//Solution for postfix expression
#include<stdio.h>
#include<conio.h>
struct stack
{
	float stk[50];
	int tos;
};

float power (float , float);
void push (struct stack * , float);		
float pop (struct stack *);
float evaluate (char []);
int isopnd (char);			//cheak whether character is operand or operator
float calculate (float , float , char);
void display (struct stack *);

int main()
{
	char postfix[50],a;
	float ans;
	printf("\nEnter the postfix expression\n");
	scanf("%s",postfix);
	ans = evaluate(postfix);
	printf("\nResult :- %f\n\n",ans);
	getch();
}

float evaluate (char postfix[])
{
	int i;
	float op1,op2,result;
	struct stack s;
	s.tos = -1;
	for (i=0;postfix[i]!='\0';i++)
	{
		if (isopnd (postfix[i]) == 1)
			push(&s,postfix[i]-'0');
		else
		{
			op2 = pop(&s);
			op1 = pop(&s);
			result = calculate(op1,op2,postfix[i]);
			push(&s,result);
		}
	}
	result = pop(&s);
	return (result);
}

int isopnd (char ch)
{
	if (ch>=48&&ch<=57)
		return 1;
	else
		return 0;
}

float calculate (float x , float y , char z)
{
	switch (z)
	{
		case '+':
			return (x+y);
		case '-':
			return (x-y);
		case '*':
			return (x*y);
		case '/':
			return (x/y);
		case '$':
			return (power(x,y));
		default:
			return (-1);
	}
}


//insert a number in stack
void push(struct stack *p,float num)
{
	if (p->tos==4)
	{
		printf("Overflow");
		return ;
	}
	p->stk[++p->tos]=num;
}

//Delete a number from stack
float pop(struct stack *p)
{
	return (p->stk[(p->tos)--]);
}

float power (float x, float y)
{
	int i;
	float exp=1.0;
	for(i=1; i<y; i++)
	{
		exp=exp*x;
	}
	return exp;
}
