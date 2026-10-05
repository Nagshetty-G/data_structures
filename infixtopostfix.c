#include <stdio.h>

char stack[100];
int top = -1;

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];


        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z'))
        {
            postfix[j] = ch;
            j++;
        }


        else if (ch == '(')
        {
            top++;
            stack[top] = ch;
        }

        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/')
        {
            top++;
            stack[top] = ch;
        }


        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }

            top--;
        }
    }


    while (top != -1)
    {
        postfix[j] = stack[top];
        j++;
        top--;
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}
