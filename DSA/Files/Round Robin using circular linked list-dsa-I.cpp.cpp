#include <iostream>
using namespace std;

struct Process
{
    int id;
    int burstTime;
    int remainingTime;
    Process* next;
};


class CircularQueue
{

    

public:
    Process* front;
    CircularQueue() 
    {
        front = nullptr;
    }

    
    void enqueue(Process* process)
    {
        if (front == nullptr) 
        {
            front = process;
            process->next = process;
        } else 
        {
            Process* rear = front->next;
            while (rear->next != front) 
            {
                rear = rear->next;
            }
            rear->next = process;
            process->next = front;
        }
    }

    
    Process* dequeue()
    {
        if (front == nullptr) 
        {
            cout << "Queue is empty." << endl;
            return nullptr;
        }

        Process* process = front; 
        if (front->next == front)
        {
            front = nullptr;
        } else
        {
            Process* rear = front->next;
            while (rear->next != front) 
            {
                rear = rear->next;
            }
            front = front->next;
            rear->next = front;
        }
        return process;
    }


    void display()
    {
        if (front == nullptr) 
        {
            cout << "Queue is empty." << endl;
        } else 
        {
            Process* temp = front;
            do 
            {
                cout << "Process " << temp->id << " (" << temp->remainingTime << "ms) -> ";
                temp = temp->next;
            } while (temp != front);
            cout << endl;
        }
    }
};

int main() {
    CircularQueue queue;

 
    Process p1 = {1, 20, 20, nullptr};
    Process p2 = {2, 25, 25, nullptr};
    Process p3 = {3, 10, 10, nullptr};
    Process p4 = {4, 15, 15, nullptr};

    
    queue.enqueue(&p1);
    queue.enqueue(&p2);
    queue.enqueue(&p3);
    queue.enqueue(&p4);

    int timeQuantum = 5; 

    cout << "Round Robin Scheduling Simulation:" << endl;

    while (queue.front != nullptr) {
        Process* currentProcess = queue.dequeue();
        if (currentProcess->remainingTime > timeQuantum) {
            cout << "Running Process " << currentProcess->id << " for " << timeQuantum << "ms." << endl;
            currentProcess->remainingTime -= timeQuantum;
            queue.enqueue(currentProcess);
        } else {
            cout << "Running Process " << currentProcess->id << " for " << currentProcess->remainingTime << "ms. (Process Completed)" << endl;
        }
        queue.display();
    }

    return 0;
}
