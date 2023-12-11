#include <iostream>
using namespace std;

class CircularQueue {
private:
    int size;
    int *queue;
    int front, rear;

public:
    CircularQueue(int size) {
        this->size = size;
        this->queue = new int[size];
        this->front = this->rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
        } else {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % size;
            }
            queue[rear] = item;
            cout << item << " enqueued to the queue." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            cout << queue[front] << " dequeued from the queue." << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            int i = front;
            cout << "Queue elements: ";
            do {
                cout << queue[i] << " ";
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
            cout << endl;
        }
    }

    ~CircularQueue() {
        delete[] queue;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(6);
    cq.enqueue(7);

    cq.display();

    return 0;
}
