    // Parenthesis
#include <iostream>
#include <stack>
using namespace std; 
bool isBalancedExp(string exp) 
{
    stack<char>stk;
    char x;
    for (int i=0; i<exp.length();i++)
    {
        if (exp[i]=='('|| exp[i]=='['||exp[i]=='{')
        {
            stk.push(exp[i]);
            continue;
        }
        if (stk.empty())
            return  false ;
        switch (exp[i])
        {
            case ')':
            x=stk.top();
            stk.pop();
            if (x=='{'||x=='[')
                return false;
            break;
        
            case '}':
            x=stk.top();
            stk.pop();
            if (x=='('||x=='[')
                return false;
            break;
            
            case ']':
            x=stk.top();
            stk.pop();
            if (x=='('||x=='{')
                return false;
            break;
        }
        
    }
    

    return (stk.empty());
}
// Prefix Evaluation
#include<bits/stdc++.h>
using namespace std;
double evaluateprefix (string prefixexp)
{
    stack<double> operandstack;
    int size = prefixexp.size()-1;
    for (int i=size; i>=0;i--)
    {
        if (isdigit (prefixexp[i]))
            operandstack.push(prefixexp[i] - '0');
        else 
        {
            double o1 = operandstack.top();
            operandstack.pop();
            double o2= operandstack.top();
            operandstack.pop();
            
            if (prefixexp[i]=='+')
                operandstack.push(o1+o2);
            
            else if (prefixexp[i]=='-')
                operandstack.push(o1-o2);
            
            else if (prefixexp[i]=='*')
                operandstack.push(o1*o2);
            
            else if (prefixexp[i]=='/')
                operandstack.push(o1/o2);
            
            else 
            {
                cout<<"Invalid Expression";
                return -1;
            }
        }
    }
    return operandstack.top();
}


// int main

int main()
{
    string expression = "()[(){()}]";
    if (isBalancedExp(expression))
        cout<<"This is a balanced expression";
    else 
        cout<<"This is not a balanced expression";

    string prefixexp= "*+54-24";
     cout<<"The result of evaluation of expression"<<prefixexp<<" is "<<evaluateprefix(prefixexp);
     return 0;
}