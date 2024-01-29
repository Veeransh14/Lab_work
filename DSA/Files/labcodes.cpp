//STACK IMPLEMENTATION
// #include<iostream>
// using namespace std;

// #define MAX 100

// class Stack {
// public:
//     int *s;
//     int top;

//     Stack(){
//        top = -1;
//        s = new int[MAX];

//     }


// bool isEmpty() {
//     if(top == -1){
//         return true;
//     }else{
//         return false;
//     }
// }

// bool isFull() {
//     if(top==MAX-1){
//         return true;
//     }else{
//         return false;
//     }
// }

// void push(int element) {
//     if (isFull()) {
//         cout << "Stack is overflow" << endl;
//         return;
//     } else {
//         s[++top] = element;
//     }
// }


// int pop() {
//     if (isEmpty()) {
//         cout << "Stack is underflow" << endl;
//         return -1;
//     } else {
//         return s[top--];
//     }
// }

// int peek() {
//     if (isEmpty()) {
//         cout << "Stack is empty" << endl;
//         return -1;
//     } else {
//         return s[top];
//     }
// }

// void traverse(){
//     int a = top;
//     while(a>=0){
//         cout<<s[a--]<<endl;
//     }
// }
// };

// int main() {
//     Stack s;
//     int choice;
//     int element;

//     while(true){
//         cout<<"1.push\n2.pop\n3.peek\n4.traverse\n5.exit\nEnter number of your choice:"<<endl;
//         cin>>choice;

//         switch(choice){
//             case 1:
//             cout<<"enter elements you want to push:"<<endl;
//             cin>>element;
//             s.push(element);
//             break;

//             case 2:
//             element = s.pop();
//             if(element!=-1){
//             cout<<"popped element:"<<element<<endl;
//             }
//             break;

//             case 3:
//             element = s.peek();
//             if(element!=-1){
//             cout<<"Peeked Element: "<<element<<endl;
//             }
//             break;

//             case 4:
//             cout<<"remaining elements:"<<endl;
//             s.traverse();
//             break;

//             case 5:
//             exit(0);

//             default:
//             cout<<"Invalid choice!"<<endl;



//         }
//     }

//     return 0;
// }

   

// #include<iostream>
// using namespace std;

// #define MAX 10

// class Stack {
// public:
//     int *s;
//     int top;

//     Stack(){
//     s = new int[MAX];
//     top = -1;
//     }
    

// bool isEmpty() {
//     return (top == -1);
// }

// void push(int element) {
//     if (top >= MAX - 1) {
//         cout << "Stack is full" << endl;
//         return;
//     } else {
//         s[++top] = element;
//     }
// }

// int pop() {
//     if (isEmpty()) {
//         cout << "Stack is empty" << endl;
//         return -1;
//     } else {
//         return s[top--];
//     }
// }

// void traverse() {
//     int a = top;
//     while (a >= 0) {
//         cout << s[a--] << " ";
//     }
//     cout << endl;
// }

// };


// int main() {
//     Stack s1, s2;
//     int n1, n2;
//     int element;
    
//     //for stack1
//     cout<<"Enter number of elements for stack1: "<<endl;
//     cin>>n1;
//     cout<<"Enter elements for stack1:"<<endl;
//     while(n1>0){
//         cin>>element;
//         s1.push(element);
//         n1--;
//     }

//     //for stack 2
//     cout<<"Enter number of elements for stack2: "<<endl;
//     cin>>n2;  
//     cout<<"Enter elements for stack2:"<<endl;
//     while(n2>0){
//         cin>>element;
//         s2.push(element);
//         n2--;
//     }
    
//     cout<<"element stored in stack1:"<<endl;
//     s1.traverse();

//     cout<<"elements stored in stack2:"<<endl;
//     s2.traverse();
   
//    Stack s3;
//    int a, b, carry=0;
//     while(!s1.isEmpty() || !s2.isEmpty()|| carry!=0){
//         if(s1.isEmpty()){
//             a=0;
//         }else{
//             a=s1.pop();
//         }

//         if(s2.isEmpty()){
//             b=0;
//         }else{
//             b=s2.pop();
//         }

//         int sum=a + b + carry;
//         s3.push(sum%10);
//         carry = sum/10;

//     }

//     cout<<"result: ";
//     s3.traverse();

  
//     return 0;
// }


//parenthesis code
// #include<iostream>
// using namespace std;
// #include <stack>

// void parenthisis(string exp){
//     stack<char> s;

//      char e;
//    for(char ch : exp){
//     if(ch=='{' ||ch=='[' ||ch=='('){
//         s.push(ch);
//     }else if(ch=='}' || ch == ']' || ch==')'){
//          e = s.top();
//         s.pop();

//         if(ch == '(' && e == ')'){
//             continue;
//         }else if(ch=='{' && e=='}'){
//             continue;
//         }else if(ch=='[' && e == ']'){
//             continue;
//         }
//     }      
//     }
        
   
//    if(!s.empty()){
//     cout<<" not balanced expression"<<endl;
//    }else{
//     cout<<"balanced expression"<<endl;
//    }

//    }


// int main(){
   
//    string exp = "[(a+b)/{c-d}";

//    parenthisis(exp);

// }

//postfix evaluation
// #include<iostream>
// using namespace std;
// #define MAX 100
// class Stack{
// public:
//     int *arr;
//     int top;

//     Stack(){
//        top = -1;
//        arr = new int[MAX];

//     }


// bool isEmpty() {
//     if(top == -1){
//         return true;
//     }else{
//         return false;
//     }
// }

// bool isFull() {
//     if(top==MAX-1){
//         return true;
//     }else{
//         return false;
//     }
// }

// void push(int element) {
//     if (isFull()) {
//         cout << "Stack is overflow" << endl;
//         return;
//     } else {
        
//         arr[++top] = element;
//     }
// }


// int pop() {
//     if (isEmpty()) {
//         cout << "Stack is underflow" << endl;
//         return -1;
//     } else {
//         return arr[top--];
//     }
// }

// int peek() {
//     if (isEmpty()) {
//         cout << "Stack is empty" << endl;
//         return -1;
//     } else {
//         return arr[top];
//     }
// }
// };
// int postfixEvaluation(string exp){

//     Stack s;
//    int result = 0;
//     for(char ch : exp){
//         if(isdigit(ch)){
//           s.push(int(ch)-48);
//         }else if(ch=='+'|| ch=='-' || ch=='*' || ch=='/'){
//             int operand2 = s.peek(); s.pop();
//             int operand1 = s.peek(); s.pop();

//             switch(ch){
//                 case '+':
//                 result = operand1+operand2;
//                 s.push(result);
//                 break;

//                 case '-':
//                 result = operand1-operand2;
//                 s.push(result);
//                 break;

//                 case '*':
//                 result = operand1*operand2;
//                 s.push(result);
//                 break;

//                 case '/':
//                 result = operand1/operand2;
//                 s.push(result);
//                 break;
//             }
            
//         }
//     }

//     int element = s.peek(); s.pop();
//     return result;  
// }

// int main(){
//     string exp = "6523+8*+3+*";

//    int result = postfixEvaluation(exp);
//    cout<<result<<endl;

// }

//prefix evaluation
// #include<iostream>
// using namespace std;
// #define MAX 100
// class Stack{
// public:
//     int *arr;
//     int top;

//     Stack(){
//        top = -1;
//        arr = new int[MAX];

//     }


// bool isEmpty() {
//     if(top == -1){
//         return true;
//     }else{
//         return false;
//     }
// }

// bool isFull() {
//     if(top==MAX-1){
//         return true;
//     }else{
//         return false;
//     }
// }

// void push(int element) {
//     if (isFull()) {
//         cout << "Stack is overflow" << endl;
//         return;
//     } else {
        
//         arr[++top] = element;
//     }
// }


// int pop() {
//     if (isEmpty()) {
//         cout << "Stack is underflow" << endl;
//         return -1;
//     } else {
//         return arr[top--];
//     }
// }

// int peek() {
//     if (isEmpty()) {
//         cout << "Stack is empty" << endl;
//         return -1;
//     } else {
//         return arr[top];
//     }
// }
// };

// int prefixEvaluation(string exp){
    
//     Stack s;
//    int result = 0;
//     for(int i=exp.length()-1; i>=0; i--){
//         char ch = exp[i];
//         if(isdigit(ch)){
//           s.push(int(ch)-48);
//         }else if(ch=='+'|| ch=='-' || ch=='*' || ch=='/'){
//             int operand1 = s.peek(); s.pop();
//             int operand2 = s.peek(); s.pop();

//             switch(ch){
//                 case '+':
//                 result = operand1+operand2;
//                 s.push(result);
//                 break;

//                 case '-':
//                 result = operand1-operand2;
//                 s.push(result);
//                 break;

//                 case '*':
//                 result = operand1*operand2;
//                 s.push(result);
//                 break;

//                 case '/':
//                 result = operand1/operand2;
//                 s.push(result);
//                 break;
//             }
            
//         }
//     }

//     int element = s.peek(); s.pop();
//     return result;  
// }



// int main(){
//     string exp;
//     cout<<"Enter expression"<<endl;
//     cin>>exp;

//     int result = prefixEvaluation(exp);
//     cout<<result<<endl;
// }


//Queue Implementation
// #include<iostream>
// using namespace std;
// #define MAX 100
// class Queue{
//     private:
    
//     int front = -1;
//     int rear = -1;
//     int *q;

//    public:
//     Queue(){
//     q = new int[MAX];
//     }

// bool isFull(){
//     if(rear==MAX-1){
//         return true;
//     }else{
//         return false;
//     }

// }

// bool isEmpty(){
//     if(rear==-1 && front == -1 || front > rear){
//         return true;
//     }else{
//         return false;
//     }
// }

// void insert(int data){

//     if(!isFull()){
        
//         q[++rear] = data; 
//         cout<<"Data entered succesfully..."<<endl;
        
//     }else{
//        cout<<"Queue is full"<<endl;
//         return;
//     }

//     if(rear==0){
//         front=0;
//     }
// }

// int remove(){
//     int data=0;
//     if(isEmpty()){
//         cout<<"Queue is Empty()";
//         return 0;
//     }else{
//         cout<<"Data deleted succesfully..."<<q[front]<<endl;
//          data = q[front];
//          front = front+1;
//          if(front>rear){
//             front = rear = -1;
//          }

//          return data;
//     }

    
// }

// void display(){
//     int a = front;
    
//     for(int i=front; i<=rear; i++){
//         cout<<q[i]<<endl;
//     }
// }
// };

// int main(){
//     Queue q1;
//     Queue q2;
//     Queue temp;
//   int choice;
//     while(true){
//     cout<<"*****MENU****"<<endl;
//     cout<<"1.INSERT"<<endl;
//     cout<<"2.REMOVE"<<endl;
//     cout<<"3.DISPLAY"<<endl;
//     cout<<"4.EXIT"<<endl;
//     int choice;

//         cout<<"Enter number to choose"<<endl;
//         cin>>choice;

//         switch(choice){
//             case 1:
//              cout<<"Enter number you want to add in queue"<<endl;
//               int n;
//               cin>>n;
//               q2.insert(n);
//           
//             break;

//             case 2:
//             q2.remove(); break;

//             case 3:
//             q2.display(); 
//             break;

//             case 4:
//             cout<<"Exited From code Sucessfully..."<<endl;
//             return 0;

//             default:
//             cout<<"Invalid Input"<<endl;

//         }


//     }

//     return 0;
    
// }


//STACK IMPLEMENTATION USING TWO QUEUES
// #include<iostream>
// using namespace std;
// #define MAX 100
// class Queue{
//     private:
    
//     int front = -1;
//     int rear = -1;
//     int *q;

//    public:
//     Queue(){
//     q = new int[MAX];
//     }

// bool isFull(){
//     if(rear==MAX-1){
//         return true;
//     }else{
//         return false;
//     }

// }

// bool isEmpty(){
//     if(rear==-1 && front == -1 || front>rear){
//         return true;
//     }else{
//         return false;
//     }
// }

// void insert(int data){

//     if(!isFull()){
        
//         q[++rear] = data; 
//         cout<<"Data entered succesfully..."<<endl;
        
//     }else{
//        cout<<"Queue is full"<<endl;
//         return;
//     }

//     if(rear==0){
//         front=0;
//     }
// }

// int remove(){
//     int data =0;
//     if(isEmpty()){
//         cout<<"Queue is Empty()";
//         return 0;
//     }else{
//         cout<<"Data deleted succesfully..."<<q[front]<<endl;
//         data = q[front];
//          front = front+1;

//     }

//     return data;
// }

// void display(){
//     int a = front;
    
//     for(int i=front; i<=rear; i++){
//         cout<<q[i]<<endl;
//     }
// }

// int peek(){
//     return q[front];
// }
// };

// int main(){
//     Queue q1;
//     Queue q2;
//     Queue temp;
//     int data;
//   int choice;
//     while(true){
//     cout<<"*****MENU****"<<endl;
//     cout<<"1.INSERT"<<endl;
//     cout<<"2.REMOVE"<<endl;
//     cout<<"3.DISPLAY"<<endl;
//     cout<<"4.PEEK"<<endl;
//     cout<<"5.EXIT"<<endl;
//     int choice;

//         cout<<"Enter number to choose"<<endl;
//         cin>>choice;

//         switch(choice){
//             case 1:
//              cout<<"Enter number you want to add:"<<endl;
//               int n;
//               cin>>n;
//               q2.insert(n);

//               while(!q1.isEmpty()){
//                 int data = q1.remove();
//                 q2.insert(data);
//               }

//               temp = q1;
//               q1 = q2;
//               q2 = temp;

//             break;

//             case 2:
//             q1.remove(); break;

//             case 3:
//             q1.display(); 
//             break;

//             case 4:
//             data = q1.peek();
//             cout<<data<<endl; 
//             break;

//             case 5:
//             cout<<"Exited From code Sucessfully..."<<endl;
//             return 0;

//             default:
//             cout<<"Invalid Input"<<endl;

//         }


//     }

//     return 0;
    
// }

//IMPLEMENTATION OF PRIORITY QUEUE
// using namespace std;
// #include <iostream>

// struct node{
//     int priority;
//     int info;
//     struct node *next;
// };
// node* front = NULL;

// void insertion(int data, int prior){
//     node* temp , * q;
//    temp = new node();
//     temp->info = data;
//     temp->priority = prior;
//     temp->next = NULL;

//     if(front==NULL || prior<front->priority){
//         temp->next = front;
//         front = temp;
//     }else{
//         q = front;
//         while(q->next!=NULL && q->next->priority<=prior){
//             q = q->next;
//         }

//         if(q->next==NULL){
//             q->next = temp;
//         }

//         if(q->next->priority>prior){
//             q->next = temp->next;
//             q->next = temp;
//         }
//     }
// }

//     int extractMax(node ll){
//         if(front==NULL){
//             cout<<"Queue is underflow"<<endl;
//             return -1;
//         }else{
//             node* temp = front;
//             int x = temp->info;
//             front = front->next;
//             delete temp;
//             return x;
//         }
//     }

//     int max(node ll){
//         if(front==NULL){
//             cout<<"Queue is underflow"<<endl;
//             return -1;
//         }else{
//             return front->info;
//         }
//     }

//     void display(node ll){
//         if(front==NULL){
//             return;
//         }else{
//            node* temp = front;
//            while(temp!=NULL){
//             cout<<temp->info<<"--#"<<temp->priority<<"-->";
//             temp = temp->next;
//            }

//            cout<<"NULL"<<endl;
//            return;
    


//         }
//     }


//     int main(){
//         int choice;
//         node ll;
//         int x;

//         while(true){
//             cout<<"***MENU***"<<endl;
//             cout<<"1.INSERTION"<<endl;
//             cout<<"2.EXTRACTMAX"<<endl;
//             cout<<"3.MAX"<<endl;
//             cout<<"4.DISPLAY"<<endl;
//             cout<<"4.EXIT"<<endl;
//             cout<<"ENTER YOUR CHOICE: "<<endl;

//             cin>>choice;

//             switch(choice){
//                 case 1:
//                 cout<<"Enter data: "<<endl;
//                 int data;  cin>>data;
//                 cout<<"Enter priority: "<<endl;
//                 int prior; cin>>prior;
//                 insertion(data, prior);
//                 break;

//                 case 2:
//                 x = extractMax(ll);
//                 cout<<"Deleted "<<x<<" Successfully...."<<endl;
//                 break;

//                 case 3:
//                 x = max(ll);
//                 cout<<x<<endl;
//                 break;

//                 case 4:
//                 display(ll);
//                 break;

//                 case 5:
//                 exit(0);
//                 break;

//                  default:
//                  cout<<"INVALID INPUT"<<endl;


 
//             }
//         }


//     }


//LINKEDLIST IMPLEMENTATION
// using namespace std;
// #include <iostream>
// struct node{
//     int data;
//     struct node* next;
// };
// struct node* front = NULL;

// void insertionAtBeg(int data){
//     node *p = new node;
//     p->data = data;
//     p->next = NULL;

//     if(front==NULL){
//         front = p;
//         return;
//     }else{
//         p->next = front;
//         front = p;
//     }
// }

// void insertionAtEnd(int data){
//     node *p = new node;
//     p->data = data;
//     p->next = NULL;
//     if(front==NULL){
//         front=p;
//         return;
//     }else{
//         node *temp = front;
//         while(temp->next!=NULL){
//             temp = temp->next;
//         }

//         temp->next = p;
//     }
// }

//     void insertionAtSpecific(int data, int key){
//         node *p = new node;
//         p->data=data;
//         p->next=NULL;

//         if(front==NULL){
//             return;
//         }else{
//             node *temp = front;
//             while(temp!=NULL && temp->data!=key){
//                 temp = temp->next;
//             }

//             if(temp==NULL){
//                 cout<<"Value not found"<<endl;
//                 return;
//             }
//             if(temp->data==key){
//                 p->next = temp->next;
//                 temp->next = p;
//                 return;
//             }
//         }


//     }

//     int deleteAtBeg(){
//         if(front==NULL){
//             return 0;
//         }else{
//             node *temp = front;
//             int x = temp->data;
//             front = front->next;
//             delete(temp);
//             return x;
//         }
//     }

//     int deleteAtEnd(){
//         if(front==NULL){
//             return 0;
//         }else{
//             node* temp = front;
//             node* q = NULL;
//             while(temp->next!=NULL){
//                 q=temp;
//                 temp = temp->next;
//             }

//             int x = temp->data;
//             q->next = NULL;
//             delete(temp);
//             return x;
//         }
//     }

// int deleteAtSpecific(int key){
//   if(front==NULL){
//   return 0;
//    }else{
//    node* temp = front;
//    node* q =  NULL;
//     while(temp!=NULL && temp->data!=key){
//     q=temp;
//     temp = temp->next;
//     }

//     if(q==NULL){
//     int x = temp->data;
//     delete(temp);
//     return x;
//     }
  
//     if(temp==NULL){
//     cout<<"Value not found"<<endl;
//     return 0;
//     }

//     if(temp->data==key){
//     q->next = temp->next;
//     int info = temp->data;
//     delete(temp);
//     return info;
//     }
//   }
// }

// void display(){
//     node* temp = front;
//     while(temp!=NULL){
//         cout<<temp->data<<"-->";
//         temp = temp->next;
//     }

//     cout<<"NULL"<<endl;

// }

// int main(){
//     node ll;
//     int choice;
//     int data;
//     int key;

//     while(true){
//     cout<<"*****MENU****"<<endl;
//     cout<<"1.INSERTATBEG"<<endl;
//     cout<<"2.INSERTATEND"<<endl;
//     cout<<"3.INSERTATSPECIFIC"<<endl;
//     cout<<"4.DELETEATBEG"<<endl;
//     cout<<"5.DELETEATEND"<<endl;
//     cout<<"6.DELETEATSPECIFIC"<<endl;
//     cout<<"7.DISPLAY"<<endl;
//     cout<<"8.EXIT"<<endl;
//     cout<<"Enter your choice: "<<endl;
//     cin>>choice;

//     switch(choice){
//         case 1:
//         cout<<"Enter data"<<endl;
//         cin>>data;
//         insertionAtBeg(data);
//         break;

//         case 2:
//         cout<<"Enter data"<<endl;
//         cin>>data;
//         insertionAtEnd(data);
//         break;

//         case 3:
//         cout<<"Enter data"<<endl;
//         cin>>data;
//         cout<<"Enter the element after which you want to insert"<<endl;
//         cin>>key;
//         insertionAtSpecific(data, key);
//         break;
        
//         case 4:
//         data = deleteAtBeg();
//         cout<<data<<" delete successfully..."<<endl;
//         break;

//         case 5:
//         data = deleteAtEnd();
//         cout<<data<<" delete successfully..."<<endl;
//         break;

//         case 6:
//         cout<<"Enter data you want to delete: "<<endl;
//         cin>>data;
//         data = deleteAtSpecific(data);
//         cout<<data<<" delete successfully..."<<endl;
//         break;

//         case 7:
//         display();
//         break;

//         case 8:
//         exit(0);
//         break;

//         default:
//         cout<<"INVALID INPUT"<<endl;
        
//     }


//     }



// }



// REVERSED LINKEDLIST IMPLEMENTATION
// using namespace std;
// #include <iostream>
// struct node{
//     int data;
//     struct node* next;
// };
// struct node* front = NULL;

// void insertionAtBeg(int data){
//     node *p = new node;
//     p->data = data;
//     p->next = NULL;

//     if(front==NULL){
//         front = p;
//         return;
//     }else{
//         p->next = front;
//         front = p;
//     }
// }

// void insertionAtEnd(int data){
//     node *p = new node;
//     p->data = data;
//     p->next = NULL;
//     if(front==NULL){
//         front=p;
//         return;
//     }else{
//         node *temp = front;
//         while(temp->next!=NULL){
//             temp = temp->next;
//         }

//         temp->next = p;
//     }
// }

//     void insertionAtSpecific(int data, int key){
//         node *p = new node;
//         p->data=data;
//         p->next=NULL;

//         if(front==NULL){
//             return;
//         }else{
//             node *temp = front;
//             while(temp!=NULL && temp->data!=key){
//                 temp = temp->next;
//             }

//             if(temp==NULL){
//                 cout<<"Value not found"<<endl;
//                 return;
//             }
//             if(temp->data==key){
//                 p->next = temp->next;
//                 temp->next = p;
//                 return;
//             }
//         }


//     }

//     int deleteAtBeg(){
//         if(front==NULL){
//             return 0;
//         }else{
//             node *temp = front;
//             int x = temp->data;
//             front = front->next;
//             delete(temp);
//             return x;
//         }
//     }

//     int deleteAtEnd(){
//         if(front==NULL){
//             return 0;
//         }else{
//             node* temp = front;
//             node* q = NULL;
//             while(temp->next!=NULL){
//                 q=temp;
//                 temp = temp->next;
//             }

//             int x = temp->data;
//             q->next = NULL;
//             delete(temp);
//             return x;
//         }
//     }

// int deleteAtSpecific(int key){
//   if(front==NULL){
//   return 0;
//    }else{
//    node* temp = front;
//    node* q =  NULL;
//     while(temp!=NULL && temp->data!=key){
//     q=temp;
//     temp = temp->next;
//     }

//     if(q==NULL){
//     int x = temp->data;
//     delete(temp);
//     return x;
//     }
  
//     if(temp==NULL){
//     cout<<"Value not found"<<endl;
//     return 0;
//     }

//     if(temp->data==key){
//     q->next = temp->next;
//     int info = temp->data;
//     delete(temp);
//     return info;
//     }
//   }
// }


// void display(){
//     node* temp = front;
//     while(temp!=NULL){
//         cout<<temp->data<<"-->";
//         temp = temp->next;
//     }

//     cout<<"NULL"<<endl;

// }

//   void reverseLinkedlist(){

//     if(front==NULL || front->next==NULL){
//         return;
//     }else{
//         cout<<"reversing"<<endl;
//         node* prev=NULL;
//         node* curr = front;
//         node* nextNode = front->next;
        

//         while(curr!=NULL){
//             nextNode = curr->next;
//             curr->next = prev;
//             prev=curr;
//             curr=nextNode;
            

           
//         }

   
//         front=prev;

//         cout<<"reversed"<<endl;
//         return;

//     }

// }

// int main(){
//     node ll;
//     int choice;
//     int data;
//     int key;

//     while(true){
//     cout<<"*****MENU****"<<endl;
//     cout<<"1.INSERTATBEG"<<endl;
//     cout<<"2.INSERTATEND"<<endl;
//     cout<<"3.INSERTATSPECIFIC"<<endl;
//     cout<<"4.DELETEATBEG"<<endl;
//     cout<<"5.DELETEATEND"<<endl;
//     cout<<"6.DELETEATSPECIFIC"<<endl;
//     cout<<"7.DISPLAY"<<endl;
//     cout<<"8.REVERSE LINKEDLIST"<<endl;
//     cout<<"9.EXIT"<<endl;
//     cout<<"Enter your choice: "<<endl;
//     cin>>choice;

//     switch(choice){
//         case 1:
//         cout<<"Enter data"<<endl;
//         cin>>data;
//         insertionAtBeg(data);
//         break;

//         case 2:
//         cout<<"Enter data"<<endl;
//         cin>>data;
//         insertionAtEnd(data);
//         break;

//         case 3:
//         cout<<"Enter data"<<endl;
//         cin>>data;
//         cout<<"Enter the element after which you want to insert"<<endl;
//         cin>>key;
//         insertionAtSpecific(data, key);
//         break;
        
//         case 4:
//         data = deleteAtBeg();
//         cout<<data<<" delete successfully..."<<endl;
//         break;

//         case 5:
//         data = deleteAtEnd();
//         cout<<data<<" delete successfully..."<<endl;
//         break;

//         case 6:
//         cout<<"Enter data you want to delete: "<<endl;
//         cin>>data;
//         data = deleteAtSpecific(data);
//         cout<<data<<" delete successfully..."<<endl;
//         break;

//         case 7:
//         display();
//         break;

//         case 8:
//         reverseLinkedlist();
//         break;


//         case 9:
//         exit(0);
//         break;

//         default:
//         cout<<"INVALID INPUT"<<endl;
        
//     }
//     }

// }




//REMOVE NTH LASTNODE FROM LL
// using namespace std;
// #include <iostream>
// struct node{
//     int data;
//     struct node* next;
// };
// struct node* front = NULL;

// void insertionAtBeg(int data){
//     node *p = new node;
//     p->data = data;
//     p->next = NULL;

//     if(front==NULL){
//         front = p;
//         return;
//     }else{
//         p->next = front;
//         front = p;
//     }
// }

// void insertionAtEnd(int data){
//     node *p = new node;
//     p->data = data;
//     p->next = NULL;
//     if(front==NULL){
//         front=p;
//         return;
//     }else{
//         node *temp = front;
//         while(temp->next!=NULL){
//             temp = temp->next;
//         }

//         temp->next = p;
//     }
// }

//     void insertionAtSpecific(int data, int key){
//         node *p = new node;
//         p->data=data;
//         p->next=NULL;

//         if(front==NULL){
//             return;
//         }else{
//             node *temp = front;
//             while(temp!=NULL && temp->data!=key){
//                 temp = temp->next;
//             }

//             if(temp==NULL){
//                 cout<<"Value not found"<<endl;
//                 return;
//             }
//             if(temp->data==key){
//                 p->next = temp->next;
//                 temp->next = p;
//                 return;
//             }
//         }


//     }

// void display(){
//     node* temp = front;
//     while(temp!=NULL){
//         cout<<temp->data<<"-->";
//         temp = temp->next;
//     }

//     cout<<"NULL"<<endl;

// }


// int removeFromnthLastNode(){
//     if(front==NULL){
//         return -1;
//     }else{
//         //count size of ll
//         node* temp = front;
//         int size=0;
//         while(temp!=NULL){
//             temp = temp->next;
//             size=size+1;
//         }

//         int n;
//         cout<<"Enter the index nth last node you want to delete"<<endl;
//         cin>>n;

//         //delete algo
//         node* q = NULL;
//         node* p = front;

//         int i=0;
//         while(i!=size-n && p!=NULL){
//             q=p;
//             p=p->next;
//             i=i+1;
//         }

//         q->next = p->next;
//         int x = p->data;
//         delete(p);
//         return x;
//     }

// }
// int main(){
//     node ll;
//     int choice;
//     int data;
//     int key;

//     while(true){
//     cout<<"*****MENU****"<<endl;
//     cout<<"1.INSERTATBEG"<<endl;
//     cout<<"2.INSERTATEND"<<endl;
//     cout<<"3.INSERTATSPECIFIC"<<endl;
//     cout<<"4.REMOVE NTH LAST NODE"<<endl;
//     cout<<"5.DISPLAY"<<endl;
//     cout<<"6.EXIT"<<endl;
//     cout<<"Enter your choice: "<<endl;
//     cin>>choice;

//     switch(choice){
//         case 1:
//         cout<<"Enter data"<<endl;
//         cin>>data;
//         insertionAtBeg(data);
//         break;

//         case 2:
//         cout<<"Enter data"<<endl;
//         cin>>data;
//         insertionAtEnd(data);
//         break;

//         case 3:
//         cout<<"Enter data"<<endl;
//         cin>>data;
//         cout<<"Enter the element after which you want to insert"<<endl;
//         cin>>key;
//         insertionAtSpecific(data, key);
//         break;

//         case 4:
//         data = removeFromnthLastNode();
//         cout<<data<<" is deleted Sucessfully"<<endl;
//         break;
        

//         case 5:
//         display();
//         break;


//         case 6:
//         exit(0);
//         break;

//         default:
//         cout<<"INVALID INPUT"<<endl;
        
//     }
//     }

// }





//CIRCULAR LL
// using namespace std;
// #include <iostream>
// struct node{
//     int data;
//     struct node* next;
// };
// struct node* front = NULL;
// struct node* follower = NULL;

// void insertionAtBeg(int data){
//     node *p = new node;
//     p->data = data;
//     p->next = NULL;
    
//     if(front==NULL){
//         front = p;
//         // p->next =front;
//         follower = front;
//         return;
//     }else{
//         p->next = front;
//         front = p;
        
//     }
// }

// void insertionAtEnd(int data){
//     node *p = new node;
//     p->data = data;
//     p->next = NULL;
//     if(front==NULL){
//         front=p;
//         p->next=front;
//         follower=front;
//         return;
//     }else{
//         node *temp = front;
//         while(temp->next!=follower){
//             temp = temp->next;
//         }

        
//         p->next = temp->next;
//         temp->next = p;
//         follower = p;
//     }
// }

//     void insertionAtSpecific(int data, int key){
//         node *p = new node;
//         p->data=data;
//         p->next=NULL;

//         if(front==NULL){
//             return;
//         }else{
//             node *temp = front;
//             while(temp!=follower && temp->data!=key){
//                 temp = temp->next;
//             }

//             if(temp==follower && temp->data!=follower->data){
//                 cout<<"Value not found"<<endl;
//                 return;
//             }


//             if(temp->data==key && temp->data==follower->data){
//                 p->next = temp->next;
//                 temp->next = p;
//                 follower = p;
//                 return;
//             }

        

//             if(temp->data==key){
//                 p->next=temp->next;
//                 temp->next = p;
//                 return;
//             }
//         }


//     }

//     int deleteAtBeg(){
//         if(front==NULL){
//             return 0;
//         }else{
//             node *temp = front;
//             int x = temp->data;
//             front = front->next;
//             follower->next = front;
//             delete(temp);
//             return x;
//         }
//     }

//     int deleteAtEnd(){
//         if(front==NULL){
//             return 0;
//         }else{
//             node* temp = front;
//             node* q = NULL;
//             while(temp!=follower){
//                 q=temp;
//                 temp = temp->next;
//             }

//             int x = temp->data;
//             q->next = temp->next;
//             follower=q;
//             delete(temp);
//             return x;
//         }
//     }

// int deleteAtSpecific(int key){
//   if(front==NULL){
//   return 0;
//    }else{
//    node* temp = front;
//    node* q =  NULL;
//     while(temp!=follower && temp->data!=key){
//     q=temp;
//     temp = temp->next;
//     }

//     if(q==NULL){
//     int x = temp->data;
//     front = front->next;
//     follower->next = front;
//     temp->next = NULL;
//     delete(temp);
//     return x;
//     }
  
    
//     if(temp==follower && temp->data==follower->data){
//         int x = temp->data;
//         follower=q;
//         delete(temp);
//         return x;
//     }else{
//     if(temp==follower && temp->data!=follower->data)
//     cout<<"Value not found"<<endl;
//     return 0;
//     }

//     //if the specific node is the first node
    

//     if(temp->data==key){
//     q->next = temp->next;
//     int info = temp->data;
//     delete(temp);
//     return info;
//     }
//   }
// }

// void display(){
//     node* temp = front;
//     while(temp!=follower){
//         cout<<temp->data<<"-->";
//         temp = temp->next;
//     }

//     cout<<temp->data;

//     cout<<"<--->start"<<endl;

// }

// void displayfollower(){
//     cout<<follower->data<<endl;
// }

// int main(){
//     node ll;
//     int choice;
//     int data;
//     int key;

//     while(true){
//     cout<<"*****MENU****"<<endl;
//     cout<<"1.INSERTATBEG"<<endl;
//     cout<<"2.INSERTATEND"<<endl;
//     cout<<"3.INSERTATSPECIFIC"<<endl;
//     cout<<"4.DELETEATBEG"<<endl;
//     cout<<"5.DELETEATEND"<<endl;
//     cout<<"6.DELETEATSPECIFIC"<<endl;
//     cout<<"7.DISPLAY"<<endl;
//     cout<<"8.DISPLAY FOLLOWER INFO"<<endl;
//     cout<<"9.EXIT"<<endl;
//     cout<<"Enter your choice: "<<endl;
//     cin>>choice;

//     switch(choice){
//         case 1:
//         cout<<"Enter data"<<endl;
//         cin>>data;
//         insertionAtBeg(data);
//         break;

//         case 2:
//         cout<<"Enter data"<<endl;
//         cin>>data;
//         insertionAtEnd(data);
//         break;

//         case 3:
//         cout<<"Enter data"<<endl;
//         cin>>data;
//         cout<<"Enter the element after which you want to insert"<<endl;
//         cin>>key;
//         insertionAtSpecific(data, key);
//         break;
        
//         case 4:
//         data = deleteAtBeg();
//         cout<<data<<" delete successfully..."<<endl;
//         break;

//         case 5:
//         data = deleteAtEnd();
//         cout<<data<<" delete successfully..."<<endl;
//         break;

//         case 6:
//         cout<<"Enter data you want to delete: "<<endl;
//         cin>>data;
//         data = deleteAtSpecific(data);
//         cout<<data<<" delete successfully..."<<endl;
//         break;

//         case 7:
//         display();
//         break;

//         case 8:
//         displayfollower();
//         break;

//         case 9:
//         exit(0);
//         break;

//         default:
//         cout<<"INVALID INPUT"<<endl;
        
//     }


//     }
// }

//ONLY QUEUE IMPLEMENTATION
// #include <iostream>
// using namespace std;
// #define MAX 100
// class Queue{
// private:
//     int front;
//     int rear;
//     int *q;

// public:
//     Queue(){
//         q = new int[MAX];
//         front=rear=-1;
//     }

//     bool isEmpty(){
//         if(front==-1 || front>rear){
//             return true;
//         } else{
//             return false;
//         }
//     }

//     bool isFull(){
//         if(rear==MAX-1){
//             return true;
//         }else{
//             return false;
//         }
//     }

//     void insert(int data){
//         if(isFull()){
//             cout<<"Queue is full"<<endl;
//             return;
//         }else{

//             q[++rear]  = data;
//             if(front=-1){
//                 front=0;
//             }            
//         }
//     }

//     int remove(){
//         int data;
//         if(isEmpty()){
//             cout<<"Queue is Empty"<<endl;
//             return -1;
//         }else{
//             data =  q[front];
//             front = front+1;         
//         }
//          return data; 
//     }

//     void display(){
//         if(isEmpty()){
//             cout<<"Queue is Empty!"<<endl;
//             return;
//         }
//         for(int i=front; i<=rear; i++){
//             cout<<q[i]<<"--";
//         }

//         cout<<endl;
//     }

//     int peek(){
//         return q[front];
//     }
// };

// int main(){
//     Queue queue;
//     int choice;
//     int data;

//     while(true){
//         cout<<"1.INSERT"<<endl;
//         cout<<"2.REMOVE"<<endl;
//         cout<<"3.PEEK"<<endl;
//         cout<<"4.DISPLAY"<<endl;
//         cout<<"5.EXIT"<<endl;

//         cout<<"Enter your choice : "<<endl;
//         cin>>choice;

//         switch(choice){
//             case 1:
//             cout<<"Enter data you want to insert: "<<endl;
//             cin>>data;
//             queue.insert(data);
//             break;

//             case 2:
//              data = queue.remove();
//              cout<<"Data deleted succesfully..."<<data<<endl;
//             break;

//             case 3:
//             data=queue.peek();
//             cout<<data<<endl;
//             break;

//             case 4:
//             queue.display();
//             break;

//             case 5:
//             exit(0);
//             break;

//             default:
//             cout<<"INVALID CHOICE!"<<endl;
        
//         }
//     }
// }

    


//BST TRAVERSE, INSERTION, TREEDIAGRAM
// #include <iostream>
// using namespace std;
// struct Node{
//     int data;
//     struct Node* left;
//     struct Node* right;
// };
// struct Node* root = nullptr;
// void insertion(int val){
//         Node* newNode = new Node;
//         newNode->data = val;
//         newNode->left = nullptr;
//         newNode->right = nullptr;

//         if(root==nullptr){
//             root = newNode;
//             cout<<"Insertion done successfully...";
//             return;
//         }else{
//             Node* p = root;
//             Node* q = nullptr;

//             while(p!=nullptr){
//                 if(p->data<newNode->data){
//                     q = p;
//                     p= p->right;
//                 }else{
//                     q=p;
//                     p=p->left;
//                 }
//             }

//             if(p==nullptr){
//                 if(q->left==nullptr && q->data>newNode->data){
//                     q->left = newNode;
//                     return;
//                 }else{
//                     q->right = newNode;
//                     return;
//                 }

//             }

//         }
// }

//   void preOrderTraversal(Node* root){
//     if(root==nullptr){
//         return;
//     }else{
//         cout<<root->data<<" ";
//         preOrderTraversal(root->left);
//         preOrderTraversal(root->right);
//         return;
//     }
//   }

// void  postOrderTraversal(Node* root){
//     if(root==nullptr){
//         return;
//     }

//     postOrderTraversal(root->left);
//     postOrderTraversal(root->right);
//     cout<<root->data<<" ";
//     return;

// }

// void inOrderTraversal(Node* root){
//     if(root==nullptr){
//         return;
//     }

//     inOrderTraversal(root->left);
//     cout<<root->data<<" ";
//     inOrderTraversal(root->right);

//     return;
// }


//  void TreeDiagramTraversal(Node* root){
//     if(root==nullptr){
//         return;
//     }

//     cout<<root->data<<" ";
//     if(root->left!=nullptr){
//         cout<<root->left->data<<" ";
//     }else{
//         cout<<"0 ";
//     }

//     if(root->right!=nullptr){
//         cout<<root->right->data<<" ";
//     }else{
//         cout<<"0 ";
//     }

//     TreeDiagramTraversal(root->left);
//     TreeDiagramTraversal(root->right);

//     return;

    
//  }
// int main(){
//     int choice;
//     int data;

//     while(true){
//         cout<<"1.INSERTION"<<endl;
//         cout<<"2.PRE-ORDER TRAVERSAL"<<endl;
//         cout<<"3.POST-ORDER TRAVERSAL"<<endl;
//         cout<<"4.INORDER TRAVERSAL"<<endl;
//         cout<<"5.TREE-DIAGRAM TRAVERSAL"<<endl;
//         cout<<"6.EXIT"<<endl;
//         cout<<"Enter your choice: "<<endl;
//         cin>>choice;

//         switch(choice){
//             case 1:
//             cout<<"Enter data: "<<endl;
//             cin>>data;
//             insertion(data);
//             break;

//             case 2:
//             preOrderTraversal(root);
//             break;

//             case 3:
//             postOrderTraversal(root);
//             break;

//             case 4:
//             inOrderTraversal(root);
//             break;

//             case 5:
//             TreeDiagramTraversal(root);
//             break;

//             case 6:
//             exit(0);
//             break;

//             default:
//             cout<<"INVALID INPUT!"<<endl;
//         }

//     }

// }


