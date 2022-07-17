#include <iostream>
#include <string.h>
using namespace std;

class stack
{
public:
    int top;
    int size;
    char *charr;

    stack(int s)
    {
        top = -1;
        size = s;
        charr = new char[size];
    }
    int isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {

            return 0;
        }
    };

    int isFull()
    {
        if (top == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };
    int push(char p)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return -1;
        }
        charr[++top] = p;
        return 0;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        return charr[top--];
    }
};
int paranthesisProblemUsingStack(stack *ss, const char *par)
{

    for (int i = 0; i < strlen(par); i++)
    {
        if (par[i] == '(' || par[i] == '{' || par[i] == '[')
        {
            ss->push(par[i]);
        }

        else if (par[i] == ')')
        {
            if (ss->isEmpty())
            {
                return 0;
            }
            else if (ss->pop() != '(')
            {
                return 0;
            }
        }
        else if (par[i] == '}')
        {
            if (ss->isEmpty())
            {
                return 0;
            }
            else if (ss->pop() != '{')
            {
                return 0;
            }
        }
        else if (par[i] == ']')
        {
            if (ss->isEmpty())
            {
                return 0;
            }
            else if (ss->pop() != '[')
            {
                return 0;
            }
        }
    }
    if (ss->isEmpty())
    {
        return 1;
    }

    return 0;
}

int main()
{
    stack s(50);

    const char *pannn = "[4-6]((8){(9-8)})";

    if (paranthesisProblemUsingStack(&s, pannn))
    {
        cout << "paranthesis mached";
    }
    else
    {
        cout << "paranthesis not mached";
    };

    return 0;
}