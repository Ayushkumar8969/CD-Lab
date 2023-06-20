//SLR(1) Parser

#include<stdio.h>
#include<stdlib.h>	
				void push(char);
				void pop();
				char input[10];
				char stk[30];
				void error();
				int top=-1;
				int ip=0;
				void push(char c)
				{
					if(top>=30)
{
					printf("stack overflow");
					}
					else
					{
					stk[++top]=c;
					}
				}
				void pop()
				{
					if(top==-1)
{
					printf("stack underflow");
					}
					else
					top--;
				}
				void display()
				{
				int i;
for(i=0;i<=top;i++)
				printf("%c",stk[i]);
				}
				void  inputdisplay()
				{
					int i;
					i=ip;
					while(input[i]!='\0')
					printf("%c",input[i++]);
				}
				void main()
{
				int flag=0;
	       			clrscr();
				printf("\nEnter the input to be parsed with the delimiter $");
				scanf("%s",input);
				push('0');
				printf("STACK                          INPUT");
				while(1)
{
				printf("\n");
display();
				printf(" --------------------------- ");
				inputdisplay();
				switch(stk[top])
{
				case '0':
					if(input[ip]=='i')
{
					ip++;
					push('i');
					push('5');
					}
					else if(input[ip]=='(')
{
					ip++;
					push('(');
					push('4');
					}
					else 
error();
					break;
				case '1':
					if(input[ip]=='+')
{
					ip++;
					push('+');
					push('6');
					}
					else if(input[ip]=='$')
{
					printf("successful parsed");
					exit(1);
					}
					else
					error();
					break;
				case '2':
					if(input[ip]=='*')
{
					ip++;
					push('*');
					push('7');
					}
					else if(input[ip]=='+'||')'||'$')
{
					pop();
					pop();
					push('E');
					if(stk[top-1]=='0')
						push('1');
					else if(stk[top-1]=='4')
						push('8');
					else 
error();
					}
					else 
error();
					break;
				case '3':
					if(input[ip]=='+'||'*'||')'||'$')
{
					pop();
					pop();
					push('T');
					if(stk[top-1]=='0')
						push('2');
					else if(stk[top-1]=='4')
						push('2');
					else if(stk[top-1]=='6')
						push('9');
					else 
error();
					}
					else 
error();
					break;
				case '4':
					if(input[ip]=='i')
{
					ip++;
					push('i');
					push('5');
					}
					else if(input[ip]=='(')
{
					ip++;
					push('(');
					push('4');
					}
					else 
error();
					break;
				case '5':
					if(input[ip]=='+'||'*'||')'||'$')
{
					pop();
					pop();
					push('F');
					if(stk[top-1]=='0')
						push('3');
					else if(stk[top-1]=='4')
						push('3');
					else if(stk[top-1]=='6')
						push('3');
					else if(stk[top-1]=='7')
						push('@');
					else 
error();
					}
					else 
error();
					break;
				case '6':
					if(input[ip]=='i')
{
					ip++;
					push('i');
					push('5');
					}
					else if(input[ip]=='(')
{
					ip++;
					push('(');
					push('4');
					}
					else 
error();
					break;
				case '7':
					if(input[ip]=='i')
{
					ip++;
					push('i');
					push('5');
					}
					else if(input[ip]=='(')
{
					ip++;
					push('(');
					push('4');
					}
					else 
error();
					break;
				case '8':
					if(input[ip]=='+')
{
					ip++;
					push('+');
					push('6');
					}
					else if(input[ip]==')')
{
					ip++;
					push(')');
					push('#');
					}
					else 
error();
break;
				case '9':
					if(input[ip]=='*')
{
					ip++;
					push('*');
					push('7');
					}
					else if(input[ip]=='+'||')'||'$')
{
					pop();
					pop();
					pop();
					pop();
					pop();
					pop();
					push('E');
					if(stk[top-1]=='0')
						push('1');
					else if(stk[top-1]=='4')
						push('8');
					else 
error();
					}
					else 
error();
					break;
				case '@':
					if(input[ip]=='+'||'*'||')'||'$')
{
					pop();
					pop();
					pop();
					pop();
					pop();
					pop();
					push('T');
					if(stk[top-1]=='0')
						push('2');
					else if(stk[top-1]=='4')
						push('2');
					else if(stk[top-1]=='6')
						push('9');
					else 
error();
					}
					else 
error();
					break;
				case '#':
					if(input[ip]=='+'||'*'||')'||'$')
{
					pop();
					pop();
					pop();
					pop();
					pop();
					pop();
					push('F');
					if(stk[top-1]=='0')
						push('3');
					else if(stk[top-1]=='4')
						push('3');
					else if(stk[top-1]=='6')
						push('3');
					else if(stk[top-1]=='7')
						push('@');
					else 
error();
					}
					else 
error();
					break;
				default: 
error(); 
break;
				}
			}
			}

			void error()
{
			printf("invalid input");
			exit(1);
			}
