// QUESTION 1

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int result = binarySearch(arr, n, key);
    if (result == -1)
        cout << "Element not found\n";
    else
        cout << "Element found at index: " << result << endl;

    return 0;
}

// QUESTION 2

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// QUESTION 3

#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n)
{
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += arr[i];
    }
    return total - sum;
}

int main()
{
    int arr[] = {1, 2, 3, 5};
    int n = 5;

    cout << "Missing number is: " << findMissingLinear(arr, n) << endl;
    return 0;
}

// QUESTION 4

// 4a

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1 = "Hello";
    string str2 = "World";
    string result = str1 + " " + str2;
    cout << "Concatenated String: " << result << endl;
    return 0;
}

// 4b

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello";
    string reversed = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversed += str[i];
    }
    cout << "Reversed String: " << reversed << endl;
    return 0;
}

// 4c

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello World";
    string result = "";
    string vowels = "AEIOUaeiou";

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (vowels.find(ch) == string::npos)
        {
            result += ch;
        }
    }

    cout << "String without vowels: " << result << endl;
    return 0;
}

// 4d

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string arr[] = {"banana", "apple", "cherry"};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    cout << "Sorted Strings:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}

// 4e

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char ch = 'A';
    char lower = tolower(ch);
    cout << "Lowercase: " << lower << endl;
    return 0;
}

// QUESTION 5

// (a) Diagonal Matrix → Only store diagonal (n elements).

// (b) Tri-diagonal Matrix → Store main + 2 diagonals (3n − 2 elements).

// (c) Lower Triangular Matrix → Store only lower half including diagonal (n(n+1)/2).

// (d) Upper Triangular Matrix → Same as lower (n(n+1)/2).

// (e) Symmetric Matrix → Store half (n(n+1)/2).

// QUESTION 6

#include <iostream>
using namespace std;

struct Element
{
    int row, col, val;
};

// Print triplet matrix
void print(Element a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i].row << " " << a[i].col << " " << a[i].val << endl;
    }
}

// Transpose of sparse matrix
void transpose(Element a[], int n)
{
    Element t[100];
    for (int i = 0; i < n; i++)
    {
        t[i].row = a[i].col;
        t[i].col = a[i].row;
        t[i].val = a[i].val;
    }

    // sort by row then col
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i].row > t[j].row ||
                (t[i].row == t[j].row && t[i].col > t[j].col))
            {
                swap(t[i], t[j]);
            }
        }
    }

    cout << "Transpose:\n";
    print(t, n);
}

// Addition of two sparse matrices
void add(Element a[], int n1, Element b[], int n2)
{
    Element c[200];
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (a[i].row < b[j].row ||
            (a[i].row == b[j].row && a[i].col < b[j].col))
        {
            c[k++] = a[i++];
        }
        else if (b[j].row < a[i].row ||
                 (b[j].row == a[i].row && b[j].col < a[i].col))
        {
            c[k++] = b[j++];
        }
        else
        { // same position
            c[k] = a[i];
            c[k].val = a[i].val + b[j].val;
            k++;
            i++;
            j++;
        }
    }
    while (i < n1)
        c[k++] = a[i++];
    while (j < n2)
        c[k++] = b[j++];

    cout << "Addition result:\n";
    print(c, k);
}

// Multiplication of two sparse matrices
void multiply(Element a[], int n1, int r1, int c1,
              Element b[], int n2, int r2, int c2)
{
    if (c1 != r2)
    {
        cout << "Multiplication not possible (dimension mismatch).\n";
        return;
    }

    int res[50][50] = {0};

    // Convert b to normal for easy multiplication
    int B[50][50] = {0};
    for (int i = 0; i < n2; i++)
    {
        B[b[i].row][b[i].col] = b[i].val;
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            res[a[i].row][j] += a[i].val * B[a[i].col][j];
        }
    }

    cout << "Multiplication result (triplets):\n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            if (res[i][j] != 0)
            {
                cout << i << " " << j << " " << res[i][j] << endl;
            }
        }
    }
}

int main()
{
    // Example matrices (3x3)
    // A =
    // 0 0 5
    // 1 0 0
    // 0 2 0
    Element A[] = {{0, 2, 5}, {1, 0, 1}, {2, 1, 2}};
    int n1 = 3;

    // B =
    // 1 0 0
    // 0 0 3
    // 0 2 0
    Element B[] = {{0, 0, 1}, {1, 2, 3}, {2, 1, 2}};
    int n2 = 3;

    cout << "Matrix A (triplets):\n";
    print(A, n1);
    cout << "Matrix B (triplets):\n";
    print(B, n2);

    // Transpose
    transpose(A, n1);

    // Addition
    add(A, n1, B, n2);

    // Multiplication (3x3 * 3x3)
    multiply(A, n1, 3, 3, B, n2, 3, 3);

    return 0;
}

// QUESTION 7

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }

    cout << "Number of inversions: " << count << endl;
    return 0;
}

// QUESTION 8

#include <iostream>
#include <set>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 2, 4, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    set<int> s(arr, arr + n);

    cout << "Number of distinct elements: " << s.size() << endl;
    return 0;
}
