#include <stdio.h>
#include <stdlib.h>

/**
 @author Md.Tanjim Mahtab Taosif (213902007) <itsmahtab007@gmail.com>
 */

int main()
{
    char infix[100],
        postfix[100],
        stack[100];

    int i,
        j,
        top = -1;

    printf("Enter an infix expression: ");
    scanf("%s", infix); // example: (a+b)*c

    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[++j] = stack[top];
                top--;
            }
            top--;
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (top != -1 && stack[top] != '(' && (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/'))
            {
                postfix[++j] = stack[top];
                top--;
            }
            stack[++top] = infix[i];
        }
        else
        {
            postfix[++j] = infix[i];
        }
    }
    while (top != -1)
    {
        postfix[++j] = stack[top];
        top--;
    }
    postfix[++j] = '\0';
    printf("Postfix expression: %s\n", postfix); // example: ab+c*

    return 0;
}