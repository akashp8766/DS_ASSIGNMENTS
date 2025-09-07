
// QUESTION 1

#include <iostream>
#include <queue>

void display_queue(std::queue<int> q)
{
    if (q.empty())
    {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    std::cout << "Queue elements: ";
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

void simple_queue_ops()
{
    std::queue<int> q;
    int choice, value;
    const int MAX_SIZE = 5;

    do
    {
        std::cout << "\n--- Simple Queue Menu ---" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Peek" << std::endl;
        std::cout << "4. Is Empty?" << std::endl;
        std::cout << "5. Display" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            if (q.size() < MAX_SIZE)
            {
                std::cout << "Enter value to enqueue: ";
                std::cin >> value;
                q.push(value);
            }
            else
            {
                std::cout << "Queue is full." << std::endl;
            }
            break;
        case 2:
            if (!q.empty())
            {
                std::cout << "Dequeued element: " << q.front() << std::endl;
                q.pop();
            }
            else
            {
                std::cout << "Queue is empty." << std::endl;
            }
            break;
        case 3:
            if (!q.empty())
            {
                std::cout << "Front element is: " << q.front() << std::endl;
            }
            else
            {
                std::cout << "Queue is empty." << std::endl;
            }
            break;
        case 4:
            if (q.empty())
            {
                std::cout << "Queue is empty." << std::endl;
            }
            else
            {
                std::cout << "Queue is not empty." << std::endl;
            }
            break;
        case 5:
            display_queue(q);
            break;
        case 6:
            std::cout << "Exiting." << std::endl;
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
        }
    } while (choice != 6);
}

// QUESTION 2

#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue
{
private:
    int arr[MAX];
    int front;
    int rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if ((rear + 1) % MAX == front)
        {
            cout << "Queue is Full!" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % MAX;
            arr[rear] = value;
            cout << "Enqueued " << value << endl;
        }
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            cout << "Dequeued " << arr[front] << endl;
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % MAX;
            }
        }
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % MAX == front);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            cout << "Queue elements: ";
            int i = front;
            while (i != rear)
            {
                cout << arr[i] << " ";
                i = (i + 1) % MAX;
            }
            cout << arr[rear] << endl;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main()
{
    CircularQueue q;
    int choice, value;

    do
    {
        cout << "\nCircular Queue Operations Menu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check if Queue is Empty" << endl;
        cout << "4. Check if Queue is Full" << endl;
        cout << "5. Display Queue" << endl;
        cout << "6. Peek (view front element)" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            if (q.isEmpty())
                cout << "Queue is Empty!" << endl;
            else
                cout << "Queue is not Empty!" << endl;
            break;
        case 4:
            if (q.isFull())
                cout << "Queue is Full!" << endl;
            else
                cout << "Queue is not Full!" << endl;
            break;
        case 5:
            q.display();
            break;
        case 6:
            q.peek();
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 7);

    return 0;
}

// QUESTION 3

#include <iostream>
using namespace std;

#define MAX 100

class Queue
{
private:
    int arr[MAX];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue is Full!" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            arr[rear] = value;
        }
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            front++;
        }
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void interleave()
    {
        if ((rear - front + 1) % 2 != 0)
        {
            cout << "Queue size is odd, cannot interleave!" << endl;
            return;
        }

        int size = rear - front + 1;
        int mid = size / 2;

        int firstHalf[mid];
        int secondHalf[mid];

        for (int i = 0; i < mid; i++)
        {
            firstHalf[i] = arr[front + i];
            secondHalf[i] = arr[front + mid + i];
        }

        int i = 0, j = 0, k = front;
        while (i < mid && j < mid)
        {
            arr[k++] = firstHalf[i++];
            arr[k++] = secondHalf[j++];
        }

        display();
    }

    int size()
    {
        return rear - front + 1;
    }
};

int main()
{
    Queue q;
    int n;

    cout << "Enter the number of elements in the queue (even number for interleaving): ";
    cin >> n;

    if (n % 2 != 0)
    {
        cout << "Enter  even number of elements!" << endl;
        return 1;
    }

    cout << "Enter " << n << " elements for the queue: ";
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        q.enqueue(value);
    }

    cout << "Original Queue: ";
    q.display();

    cout << "Interleaved Queue: ";
    q.interleave();

    return 0;
}

// Question 4

#include <iostream>
using namespace std;

#define MAX_CHAR 256 // For ASCII characters

void firstNonRepeating(string str)
{
    int freq[MAX_CHAR] = {0};
    char queue[1000];
    int front = 0, rear = 0;

    for (int i = 0; i < str.length(); i++)
    {
        char current = str[i];

        freq[current]++;

        if (freq[current] == 1)
        {
            queue[rear] = current;
            rear++;
        }

        while (front < rear && freq[queue[front]] > 1)
        {
            front++;
        }

        if (front < rear)
        {
            cout << queue[front] << " ";
        }
        else
        {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    firstNonRepeating(str);

    return 0;
}

// QUESTION 5

#include <iostream>
#include <queue>

class StackUsingTwoQueues
{
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        std::swap(q1, q2);
    }
    void pop()
    {
        if (!q1.empty())
            q1.pop();
    }
    int top()
    {
        if (!q1.empty())
            return q1.front();
        return -1;
    }
    bool empty()
    {
        return q1.empty();
    }
};

class StackUsingOneQueue
{
private:
    std::queue<int> q;

public:
    void push(int x)
    {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        if (!q.empty())
            q.pop();
    }
    int top()
    {
        if (!q.empty())
            return q.front();
        return -1;
    }
    bool empty()
    {
        return q.empty();
    }
};

// Additional 1

#include <iostream>
#include <string>
#include <queue>

void generateBinary(int n)
{
    std::queue<std::string> q;
    q.push("1");

    while (n-- > 0)
    {
        std::string s1 = q.front();
        q.pop();
        std::cout << s1 << std::endl;
        std::string s2 = s1;
        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
}

// Additional 2

#include <iostream>
#include <queue>

int findMinIndex(std::queue<int> &q, int sort_length)
{
    int min_val = q.front();
    int min_index = -1;
    for (int i = 0; i < sort_length; i++)
    {
        int temp = q.front();
        q.pop();
        if (temp <= min_val)
        {
            min_val = temp;
            min_index = i;
        }
        q.push(temp);
    }
    return min_index;
}

void moveMinToRear(std::queue<int> &q, int min_index)
{
    int min_val = -1;
    for (int i = 0; i <= min_index; i++)
    {
        int temp = q.front();
        q.pop();
        if (i == min_index)
        {
            min_val = temp;
            continue;
        }
        q.push(temp);
    }
    q.push(min_val);
}

void sortQueue(std::queue<int> &q)
{
    for (int i = 1; i <= q.size(); i++)
    {
        int min_index = findMinIndex(q, q.size() - i + 1);
        moveMinToRear(q, min_index);
    }
}

// Additional 3

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

bool canSortQueue(std::queue<int> &q)
{
    std::stack<int> s;
    int expected = 1;

    while (!q.empty())
    {
        if (q.front() == expected)
        {
            expected++;
            q.pop();
        }
        else if (!s.empty() && s.top() == expected)
        {
            expected++;
            s.pop();
        }
        else
        {
            s.push(q.front());
            q.pop();
        }
    }

    while (!s.empty() && s.top() == expected)
    {
        expected++;
        s.pop();
    }

    return s.empty();
}

int main()
{
    std::queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (canSortQueue(q))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}

// Additional 4

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int countStudents(std::vector<int> &students, std::vector<int> &sandwiches)
{
    std::queue<int> studentQueue;
    for (int student : students)
    {
        studentQueue.push(student);
    }

    std::stack<int> sandwichStack;
    for (int i = sandwiches.size() - 1; i >= 0; --i)
    {
        sandwichStack.push(sandwiches[i]);
    }

    int unableToEatCount = 0;
    while (!studentQueue.empty() && unableToEatCount < studentQueue.size())
    {
        if (studentQueue.front() == sandwichStack.top())
        {
            studentQueue.pop();
            sandwichStack.pop();
            unableToEatCount = 0;
        }
        else
        {
            int student = studentQueue.front();
            studentQueue.pop();
            studentQueue.push(student);
            unableToEatCount++;
        }
    }
    return studentQueue.size();
}

int main()
{
    std::vector<int> students = {1, 1, 0, 0};
    std::vector<int> sandwiches = {0, 1, 0, 1};

    int result = countStudents(students, sandwiches);
    std::cout << result << std::endl;

    return 0;
}
