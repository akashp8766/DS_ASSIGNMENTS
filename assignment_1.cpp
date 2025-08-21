// QUESTION 1

#include <iostream>
using namespace std;

int arr[100];
int n = 0;

int main()
{
    int choice;
    do
    {
        cout << "\n——MENU——-\n";
        cout << "1.CREATE\n";
        cout << "2.DISPLAY\n";
        cout << "3.INSERT\n";
        cout << "4.DELETE\n";
        cout << "5.LINEAR SEARCH\n";
        cout << "6.EXIT\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            break;
        }
        case 2:
        {
            cout << "Array: ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        case 3:
        {
            int pos, val;
            cout << "Enter position to insert (0-based): ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            for (int i = n; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos] = val;
            n++;
            break;
        }
        case 4:
        {
            int pos;
            cout << "Enter position to delete (0-based): ";
            cin >> pos;
            for (int i = pos; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n--;
            break;
        }
        case 5:
        {
            int val;
            bool found = false;
            cout << "Enter value to search: ";
            cin >> val;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == val)
                {
                    cout << "Found at index: " << i << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Not found.\n";
            break;
        }
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}

// QUESTION 2

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result[n], k = 0;
    for (int i = 0; i < n; i++)
    {
        bool exists = false;
        for (int j = 0; j < k; j++)
        {
            if (arr[i] == result[j])
            {
                exists = true;
                break;
            }
        }
        if (!exists)
            result[k++] = arr[i];
    }

    cout << "Unique array: ";
    for (int i = 0; i < k; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}

// QUESTION 3

#include <iostream>
using namespace std;
int main()
{
    int i;
    int arr[5] = {1};
    for (i = 0; i < 5; i++)
        printf("%d", arr[i]);
    return 0;
}

// output 10000

// QUESTION 4

#include <iostream>
using namespace std;

// 4a

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// 4b

int main()
{
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2] = {{0, 0}, {0, 0}};

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                c[i][j] += a[i][k] * b[k][j];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    return 0;
}

// 4c

int main()
{
    int arr[2][2] = {{1, 2}, {3, 4}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// QUESTION 5

int main()
{
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    // Row sums
    for (int i = 0; i < 3; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < 3; j++)
        {
            rowSum += matrix[i][j];
        }
        cout << rowSum << endl;
    }

    // Column sums
    for (int j = 0; j < 3; j++)
    {
        int colSum = 0;
        for (int i = 0; i < 3; i++)
        {
            colSum += matrix[i][j];
        }
        cout << colSum << endl;
    }

    return 0;
}
