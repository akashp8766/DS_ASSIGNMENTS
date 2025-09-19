#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int v) : data(v), next(nullptr) {}
};

struct PolyNode
{
    int coeff;
    int pow;
    PolyNode *next;
    PolyNode(int c, int p) : coeff(c), pow(p), next(nullptr) {}
};

// QUESTION 1
void insertAtBeginning(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}
void insertAtEnd(Node *&head, int val)
{
    Node *n = new Node(val);
    if (!head)
    {
        head = n;
        return;
    }
    Node *t = head;
    while (t->next)
        t = t->next;
    t->next = n;
}
void insertBeforeValue(Node *&head, int val, int target)
{
    if (!head)
        return;
    if (head->data == target)
    {
        insertAtBeginning(head, val);
        return;
    }
    Node *prev = nullptr;
    Node *cur = head;
    while (cur && cur->data != target)
    {
        prev = cur;
        cur = cur->next;
    }
    if (cur)
    {
        Node *n = new Node(val);
        prev->next = n;
        n->next = cur;
    }
}
void insertAfterValue(Node *&head, int val, int target)
{
    Node *cur = head;
    while (cur && cur->data != target)
        cur = cur->next;
    if (cur)
    {
        Node *n = new Node(val);
        n->next = cur->next;
        cur->next = n;
    }
}
void deleteFromBeginning(Node *&head)
{
    if (!head)
        return;
    Node *t = head;
    head = head->next;
    delete t;
}
void deleteFromEnd(Node *&head)
{
    if (!head)
        return;
    if (!head->next)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *prev = nullptr;
    Node *cur = head;
    while (cur->next)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = nullptr;
    delete cur;
}
void deleteValue(Node *&head, int val)
{
    while (head && head->data == val)
    {
        Node *t = head;
        head = head->next;
        delete t;
    }
    Node *cur = head;
    while (cur && cur->next)
    {
        if (cur->next->data == val)
        {
            Node *t = cur->next;
            cur->next = t->next;
            delete t;
        }
        else
            cur = cur->next;
    }
}
int searchNode(Node *head, int val)
{
    int pos = 1;
    while (head)
    {
        if (head->data == val)
            return pos;
        head = head->next;
        pos++;
    }
    return -1;
}
void displayList(Node *head)
{
    if (!head)
    {
        cout << "Empty\n";
        return;
    }
    Node *cur = head;
    while (cur)
    {
        cout << cur->data;
        if (cur->next)
            cout << "->";
        cur = cur->next;
    }
    cout << "\n";
}

// QUESTION 2
int countOccurrencesAndDeleteAll(Node *&head, int key)
{
    int count = 0;
    while (head && head->data == key)
    {
        count++;
        Node *t = head;
        head = head->next;
        delete t;
    }
    Node *cur = head;
    while (cur && cur->next)
    {
        if (cur->next->data == key)
        {
            count++;
            Node *t = cur->next;
            cur->next = t->next;
            delete t;
        }
        else
            cur = cur->next;
    }
    return count;
}

// QUESTION 3
int findMiddle(Node *head)
{
    if (!head)
        return -1;
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

// QUESTION 4
void reverseList(Node *&head)
{
    Node *prev = nullptr;
    Node *cur = head;
    while (cur)
    {
        Node *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
}

// Additional 1
Node *getIntersectionNode(Node *headA, Node *headB)
{
    if (!headA || !headB)
        return nullptr;
    Node *a = headA;
    Node *b = headB;
    while (a != b)
    {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

// Additional 2
Node *reverseKGroupUtil(Node *head, int k)
{
    Node *cur = head;
    int cnt = 0;
    while (cur && cnt < k)
    {
        cur = cur->next;
        cnt++;
    }
    if (cnt < k)
        return head;
    Node *prev = nullptr;
    cur = head;
    for (int i = 0; i < k; i++)
    {
        Node *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head->next = reverseKGroupUtil(cur, k);
    return prev;
}
Node *reverseKGroup(Node *head, int k)
{
    if (k <= 1)
        return head;
    return reverseKGroupUtil(head, k);
}

// Additional 3
bool detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
void removeLoop(Node *head)
{
    if (!head)
        return;
    Node *slow = head;
    Node *fast = head;
    bool found = false;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            found = true;
            break;
        }
    }
    if (!found)
        return;
    slow = head;
    if (slow == fast)
    {
        while (fast->next != slow)
            fast = fast->next;
        fast->next = nullptr;
        return;
    }
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = nullptr;
}

// Additional 4
void rotateLeft(Node *&head, int k)
{
    if (!head || k == 0)
        return;
    int n = 0;
    Node *t = head;
    while (t)
    {
        n++;
        t = t->next;
    }
    k = k % n;
    if (k == 0)
        return;
    Node *cur = head;
    for (int i = 1; i < k; i++)
        cur = cur->next;
    Node *newHead = cur->next;
    cur->next = nullptr;
    Node *tail = newHead;
    while (tail && tail->next)
        tail = tail->next;
    if (tail)
        tail->next = head;
    head = newHead;
}

// Additional 5
PolyNode *insertPolyEnd(PolyNode *&head, int coeff, int pow)
{
    PolyNode *n = new PolyNode(coeff, pow);
    if (!head)
    {
        head = n;
        return head;
    }
    PolyNode *t = head;
    while (t->next)
        t = t->next;
    t->next = n;
    return head;
}
PolyNode *addPolynomials(PolyNode *p1, PolyNode *p2)
{
    PolyNode *res = nullptr;
    while (p1 && p2)
    {
        if (p1->pow == p2->pow)
        {
            int sum = p1->coeff + p2->coeff;
            if (sum)
                insertPolyEnd(res, sum, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow)
        {
            insertPolyEnd(res, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else
        {
            insertPolyEnd(res, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }
    while (p1)
    {
        insertPolyEnd(res, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2)
    {
        insertPolyEnd(res, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return res;
}
void displayPoly(PolyNode *head)
{
    if (!head)
    {
        cout << "Empty\n";
        return;
    }
    PolyNode *t = head;
    bool first = true;
    while (t)
    {
        if (!first)
            cout << " + ";
        cout << "[" << t->coeff << "," << t->pow << "]";
        first = false;
        t = t->next;
    }
    cout << "\n";
}

void freeList(Node *&head)
{
    while (head)
    {
        Node *t = head;
        head = head->next;
        delete t;
    }
}

void freePoly(PolyNode *&head)
{
    while (head)
    {
        PolyNode *t = head;
        head = head->next;
        delete t;
    }
}

int main()
{
    return 0;
}
