
// QUESTION 1

#include <iostream>
using namespace std;
int main()
{
    const int MAX = 100;
    int st[MAX];
    int top = -1;
    while (true)
    {
        int c;
        if (!(cin >> c))
            return 0;
        if (c == 0)
            break;
        if (c == 1)
        {
            int x;
            cin >> x;
            if (top == MAX - 1)
                cout << "Overflow\n";
            else
                st[++top] = x;
        }
        else if (c == 2)
        {
            if (top == -1)
                cout << "Underflow\n";
            else
            {
                cout << st[top--] << "\n";
            }
        }
        else if (c == 3)
        {
            cout << (top == -1) << "\n";
        }
        else if (c == 4)
        {
            cout << (top == MAX - 1) << "\n";
        }
        else if (c == 5)
        {
            if (top == -1)
                cout << "Empty\n";
            else
            {
                for (int i = top; i >= 0; i--)
                    cout << st[i] << (i == 0 ? '\n' : ' ');
            }
        }
        else if (c == 6)
        {
            if (top == -1)
                cout << "Empty\n";
            else
                cout << st[top] << "\n";
        }
    }
    return 0;
}

// QUESTION 2

#include <iostream>
using namespace std;
int main()
{
    const int N = 2000;
    char s[N];
    if (!cin.getline(s, N))
        return 0;
    int len = 0;
    while (s[len] != '\0')
        len++;
    char st[N];
    int top = -1;
    for (int i = 0; i < len; i++)
        st[++top] = s[i];
    while (top >= 0)
    {
        cout << st[top--];
    }
    cout << "\n";
    return 0;
}

// QUESTION 3

#include <iostream>
using namespace std;
int main()
{
    const int N = 2000;
    char s[N];
    if (!cin.getline(s, N))
        return 0;
    char st[N];
    int top = -1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[')
            st[++top] = c;
        else if (c == ')' || c == '}' || c == ']')
        {
            if (top == -1)
            {
                cout << "NO\n";
                return 0;
            }
            char t = st[top--];
            if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '['))
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << (top == -1 ? "YES\n" : "NO\n");
    return 0;
}

// QUESTION 4

#include <iostream>
using namespace std;
int prec(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}
int main()
{
    const int N = 2000;
    char s[N];
    if (!cin.getline(s, N))
        return 0;
    char st[N];
    int top = -1;
    char out[N * 2];
    int oi = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        if (c == ' ')
            continue;
        bool isal = (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
        if (isal)
            out[oi++] = c;
        else if (c == '(')
            st[++top] = c;
        else if (c == ')')
        {
            while (top >= 0 && st[top] != '(')
                out[oi++] = st[top--];
            if (top >= 0)
                top--;
        }
        else
        {
            while (top >= 0 && st[top] != '(' && ((prec(st[top]) > prec(c)) || (prec(st[top]) == prec(c) && c != '^')))
            {
                out[oi++] = st[top--];
            }
            st[++top] = c;
        }
    }
    while (top >= 0)
        out[oi++] = st[top--];
    out[oi] = '\0';
    cout << out << "\n";
    return 0;
}

// QUESTION 5

#include <iostream>
using namespace std;
long long ipow(long long a, long long b)
{
    long long r = 1;
    while (b > 0)
    {
        if (b & 1)
            r = r * a;
        a = a * a;
        b >>= 1;
    }
    return r;
}
int main()
{
    const int N = 5000;
    char s[N];
    if (!cin.getline(s, N))
        return 0;
    long long st[N];
    int top = -1;
    int i = 0;
    while (s[i] != '\0')
    {
        while (s[i] == ' ')
            i++;
        if (s[i] == '\0')
            break;
        if ((s[i] == '-' && s[i + 1] >= '0' && s[i + 1] <= '9') || (s[i] >= '0' && s[i] <= '9'))
        {
            bool neg = false;
            if (s[i] == '-')
            {
                neg = true;
                i++;
            }
            long long num = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            if (neg)
                num = -num;
            st[++top] = num;
        }
        else
        {
            char op = s[i++];
            if (op == ' ')
                continue;
            long long b = st[top--];
            long long a = st[top--];
            long long res = 0;
            if (op == '+')
                res = a + b;
            else if (op == '-')
                res = a - b;
            else if (op == '*')
                res = a * b;
            else if (op == '/')
                res = a / b;
            else if (op == '^')
                res = ipow(a, b);
            st[++top] = res;
        }
    }
    if (top >= 0)
        cout << st[top] << "\n";
    return 0;
}
