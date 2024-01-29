# include <iostream>
//# include <queue>
using namespace std;
class queue
{
   int q[100];
   int front=-1;
   int rear=-1;
   
   public:
   bool isfull()
   {
        if (rear== 99)
            return 1;
        else 
            return 0;
   }
   bool isempty()
   {
        if (rear==-1 && front==-1 || (front>rear))
            return 1;
        else 
            return 0;
   }
   void insert(int x)
   {
        if (isfull())
            cout<<"Queue Overflow"<<endl;
        else
        {
            rear++;
            q[rear]=x;
        }
            
   }
   int remove()
   {
       if (isempty())
       {
           cout<<"Queue Underflow"<<endl;
           return -1;
       }
       else 
       {
           return q[front++];
       }
   }
   
       
   
};
int main()
{
    queue q1,q2;
    void push(int y)
    {
        if (q1.isfull())
        {
            cout<<"Queue overflow"<<endl;
        }
        else 
        {
            q1.insert(y);
        }
    }
    int pop()
    {
        while (!q1.isempty())
        {
            a=q1.delete()
            if (!q1.isempty())
            {
                q2.insert(a)
            }
            else 
            {
                cout<<x<<endl;
            }
        }
    }
    q1.insert(10);
    q2.insert(20);

    return 0;
}