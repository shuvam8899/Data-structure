#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct STACK
{
    int size;
    int top;
    char *arr;
};
bool isemp(struct STACK *s)
{
    if (s->top == -1)
    {
        return true;
    }
    return false;
}
bool isful(struct STACK *s)
{
    if (s->top == s->size - 1)
    {
        return true;
    }
    return false;
}
void push(struct STACK *s, char element)
{
    if (isful(s))
    {
        printf("Stack is Full.\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = element;
    }
}
char pop(struct STACK *s)
{
    char element_removed = '\0';
    if (isemp(s))
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        element_removed = s->arr[s->top];
        s->top--;
    }
    return element_removed;
}
int main()
{
    struct STACK Stack1;
    Stack1.top = -1;
    int size_of_exp;
    char exp[100];
    // printf("Now enter expression:");
    scanf("%s", exp);
    size_of_exp = strlen(exp);
    Stack1.size = size_of_exp;
    Stack1.arr = (char *)malloc(sizeof(char) * size_of_exp);
    for (int i = 0; i < size_of_exp; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            push(&Stack1, exp[i]);
            continue;
        }
        if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if ((Stack1.arr[Stack1.top] == '{' && exp[i] == '}') || (Stack1.arr[Stack1.top] == '(' && exp[i] == ')') || (Stack1.arr[Stack1.top] == '[' && exp[i] == ']'))
            {
                pop(&Stack1);
            }
            else
            {
                printf("Unbalanced.\n");
                return 0;
            }
        }
    }
    if (Stack1.top == -1)
    {
        printf("Balanced.\n");
    }
    else
    {
        printf("Unbalanced.\n");
    }
    return 0;
}
