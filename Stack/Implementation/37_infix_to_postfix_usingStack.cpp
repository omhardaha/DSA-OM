#include <iostream>
#include <cstring>
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
            return 1;
        else
            return 0;
    };

    int isFull()
    {
        if (top == size - 1)
            return 1;
        else
            return 0;
    };
    char stackTop()
    {
        return charr[top];
    }
    char stackBottom()
    {
        return charr[0];
    }
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
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        return charr[top--];
    }
};

int isOperator(char a)
{
    if (a == '+' || a == '-' || a == '/' || a == '*')
        return 1;

    return 0;
};

int isPresidents(char a)
{
    if (a == '+' || a == '-')
        return 2;

    else if (a == '/' || a == '*')
        return 3;

    return 1;
};

string infixToPostfixExpression(string par)
{
    int ii = 0; // infix Index
    int pi = 0; // post fix index
    stack *ss = new stack(par.length());
    string postfix = par;
    while (ii != par.length())
    {
        if (isOperator(par[ii]))
        {
            if (isPresidents(par[ii]) > isPresidents(ss->stackTop()))
                ss->push(par[ii++]);
            else
                postfix[pi++] = ss->pop();
        }
        else
            postfix[pi++] = par[ii++];
    }
    while (!ss->isEmpty())
        postfix[pi++] = ss->pop();
    return postfix;
}

int main()
{
    string infix = "x-y/z-k*d"; //postfix is xyz/-kd*-
    cout << infixToPostfixExpression(infix);
    return 0;
}
