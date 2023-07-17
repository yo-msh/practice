#include <iostream>
#include "function.h"
// #include "choice.h"
// using namespace std;

int main()
{
    int i, n, ch;
    struct Array arr;

    bool loop = true;

    cout << "enter the size of the array : " << endl;
    cin >> arr.size;

    arr.A = new int[arr.size];
    arr.length = 0;

    cout << "enter number of elements : " << endl;
    cin >> arr.length;

    cout << "enter elements : " << endl;

    for (i = 0; i < arr.length; i++)
        cin >> arr.A[i];

    while (loop)
    {
        cout << "\nEnter the operation you want to perform :\n"
             << "1. Display" << endl
             << "2. Append" << endl
             << "3. Insert" << endl
             << "4. Remove" << endl
             << "5. Delete" << endl
             << "6. Bubble Sort" << endl
             << "7. IsSorted?" << endl
             << "8. Linear Search" << endl
             << "9. Binary Search" << endl
             << "20. Exit" << endl
             << endl;

        cin >> ch;

        // loop = choi(ch);

        int x, y, z;
        bool a;

        switch (ch)
        {
        case 1:
            Display(&arr);
            break;

        case 2:
            cout << "enter the element you want to append : ";
            cin >> x;
            Append(&arr, x);
            break;

        case 3:
            cout << "enter the element you want to insert : ";
            cin >> x;
            cout << "enter the index : ";
            cin >> y;

            Insert(&arr, x, y);
            break;

        case 4:
            Remove(&arr);
            break;

        case 5:
            cout << "enter the index you want to delete from : ";
            cin >> y;
            Delete(&arr, y);
            break;

        case 6:
            BubbleSort(&arr);
            cout << "sucessfully sorted" << endl;
            break;

        case 7:
            a = IsSorted(&arr);

            if (a)
                cout << "sorted\n";
            else
                cout << "not sorted\n";

            break;

        case 8:
            cout << "enter the element you want to search : ";
            cin >> x;

            z = LinSrch(&arr, x);

            if (x >= 0)
                cout << "the element exist at the index " << z << endl;
            else
                cout << "the element doesnt exists" << endl;

            break;

        case 9:
            a = IsSorted(&arr);
            if (a)
            {
                cout << "enter the element you want to search : ";
                cin >> x;
                z = BinSrch(&arr, x);
                if (x >= 0)
                    cout << "the element exist at the index " << z << endl;
                else
                    cout << "the element doesnt exists" << endl;
            }

            else
                cout << "unsuccessful\n"
                     << "cant perform binary search because the array isnt sorted\n"
                     << "either sort it first or use linear search" << endl;

            break;

        case 20:
            loop = false;
            cout << "thx UwU";
            break;

        default:
            break;
        }
    }

    return 0;
}