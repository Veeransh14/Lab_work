// arithmatics using stacks
#include<iostream>

#include<cmath>
using namespace std;
//user defined data type (abstract data type)
class stack {
    private:
    //setting the value of top to 0 (top is to a list what pointer is to an array)
    //value of top starts from -1
    int top = -1;
    int size;
    //stack is basically an array which has a property of LIFO(last in first out)
    int arr[100];
    public: 
    //push function(input function)
    void push(int n){
        //checking if the stack is full 
        if (top==99){
            cout<<"stackoverflow"<<endl;
        }
        else{
        //incrementing the value of top (pointer) and assingning the value to the place where the top points 
        top++;
        arr[top] = n;
        }
    }
    //pop function(output function)
    int pop(){
        //checking if the stack is empty 
        if (top==-1){
            cout<<"stackunderflow"<<endl;
        }
        else{
        //decrementing the value of top (pointer) and assingning the value to the place where the top points 
            return (arr[top--]);
        }   
    }    
    //function to check is the stack is empty or not 
    bool isempty(){
        if (top==-1){
            //cout<<"stackunderflow"<<endl;
            return true;
        }
        else{
            return false;
        }
        
    }
    //function to check is the stack is full or not
    bool isfull(){
        if(top==99){
            //cout<<"stackunderflow"<<endl;
            return true;
        }
        else{
            return false;
        }
        
    }
    //this funtion just prints the last inputted value does not return it 
    //pop returns the value 
    //if you pop the value gets deleted from the stack
    //if you peek the value remians in the satck 
    void peek(){
        cout<<arr[top]<<endl;
    }
    //function to display the values inside the stack
    //not required
    void display(){
        for(int x=top;x>-1;x--){
            cout<<arr[x];
        }
    }
};

int main(){
    stack s1,s2,s3;
    string first,second;
    //taking input as string 
    cout<<"\nenter first number:"<<endl;
    cin>>first;
    cout<<"\nenter second number:"<<endl;
    cin>>second;
    int x = first.length();
    int y = second.length();
    //10 raised to (string legnth - 1)
    //we add 0.5 bcoz 10 raised to 4 is interpreted by compiler as 9999
    int p = (int)(pow(10,x-1)+0.5);
    int q = (int)(pow(10,y-1)+0.5);
    //converting string to integer
    int number1 = stoi(first);
    int number2 = stoi(second);
    //one way of inserting numbers on to the stack
    //divide by 10 raised to number legnth 
    //ex.:56467/10raisedto4 = 5 and so on
    while (number1>0){
        int i=number1/p;
        s1.push(i);
        number1 = number1%p;
        p=p/10;
    }
    //s1.display();
    cout<<""<<endl;
    char ch ;
    //secong way of inserting numbers on to the stack
    //string is an array of characters 
    //indexing the characters -> converting them to int -> pushing them to stack  
    for (int i = 0; i < y; i++) {
            ch = second.at(i);
            int x = int(ch-'0');
            s2.push(x);
        }
    //s2.display();
    int carry = 0;
    while(!s1.isempty() || !s2.isempty()){
        int a; 
        int b;
        int c;
        if (!s1.isempty()){
            a=s1.pop();
        }
        else{
            a=0;
        }
        if(!s2.isempty()){
            b=s2.pop();
        }
        else{
            b=0;
        }
        c=a+b+carry;
        carry =c/10;
        s3.push(c%10);
    }
    s3.display();
    return 0;
}