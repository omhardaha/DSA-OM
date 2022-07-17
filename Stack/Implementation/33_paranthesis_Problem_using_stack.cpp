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
        if (par[i] == '(')
        {
            ss->push('(');
        }
        if (par[i] == ')')
        {
            
            if (ss->isEmpty())
            {
                return 0;
            }

            ss->pop();
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
    stack s(50); /// defines the 50 /c/h/a/r/i/n/t/ stack

    // s.push(45);
    // s.push(445);
    // s.pop();

    const char *pannn = "[()]{}{[()()]()}";

    if (paranthesisProblemUsingStack(&s, pannn))
    {
        cout << "paran.. mached";
    }
    else
    {
        cout << "paran.. not mached";
    };

    return 0;
}