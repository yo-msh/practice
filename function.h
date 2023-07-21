using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array *temp)
{
    int i;
    for (i = 0; i < temp->length; i++)
        cout << temp->A[i] << " ";

    cout << endl;
}

void Append(struct Array *temp, int x)
{
    if (temp->size == temp->length)
        cout << "the array is full, delete any element and try again:" << endl;
    else
    {
        temp->A[temp->length] = x;
        temp->length++;
        cout << "successful";
    }
}

void Insert(struct Array *temp, int x, int y)
{
    if (temp->size == temp->length && !(y >= 0 && y <= temp->length))
        cout << "error and try again:" << endl;
    else
    {
        int i;
        for (i = temp->length; i > y; i--)
            temp->A[i] = temp->A[i - 1];

        temp->A[i] = x;

        temp->length++;
        cout << "successful";

    }
}

void Remove(struct Array *temp)
{
    temp->length--;
}

void Delete(struct Array *temp, int y)
{
    if (temp->size == temp->length && !(y >= 0 && y <= temp->length))
        cout << "error and try again:" << endl;
    else
    {
        temp->length--;

        int i;
        for (i = y; i < temp->length; i++)
            temp->A[i] = temp->A[i + 1];
        
        cout << "successful";
    }
}

void BubbleSort(struct Array *temp)
{
    int i, j, k;

    for (i = 0; i < temp->length; i++)
    {
        for (j = 0; j < temp->length - 1; j++)
        {
            if (temp->A[j] > temp->A[j + 1])
            {
                k = temp->A[j];
                temp->A[j] = temp->A[j + 1];
                temp->A[j + 1] = k;
            }
        }
    }
}

bool IsSorted(struct Array *temp)
{
    int i;

    for (i = 0; i < temp->length - 1; i++)
    {
        if (temp->A[i] > temp->A[i + 1])
            return false;
    }

    return true;
}

int LinSrch(struct Array *temp, int x)
{
    int i, key;
    key = x;

    for(i = 0; i < temp->length; i++)
    {
        if(key == temp->A[i])
            return i;
    }

    return -1;
}

int BinSrch(struct Array *temp, int x)
{
    int l = 0, h = temp->length - 1, mid, key;

    key = x;

    while (l <= h)
    {
        mid = (l + h) / 2;

        if (key == temp->A[mid])
            return mid;
        else if (key > temp->A[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }

    return -1;
}

void InsSort(struct Array *temp)
{
    int i,j,key;

    for(i = 1; i < temp->length; i++)
    {
        key = temp->A[i];
        j = i - 1;

        while(temp->A[j] > key && j >= 0)
        {
            temp->A[j+1] = temp->A[j];
            j--;
        }

        temp->A[j+1] = key;
    }
}
