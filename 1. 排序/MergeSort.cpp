#include <iostream>
#include <ctime>

using namespace std;

const int MAXN = 10000;
int arr[MAXN];
int tmpArr[MAXN];

int generateArr(int arrSize, int range)
{
    srand(time(NULL));
    for (int i = 0; i < arrSize; ++i)
        arr[i] = rand() % range;
}
void traverseArr(int arrSize)
{
    for (int i = 0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int left, int right, int mid)
{
    int p1 = left, p2 = mid + 1;
    int cnt = left;
    while (p1 <= mid && p2 <= right)
    {
        if (arr[p1] <= arr[p2])
            tmpArr[cnt] = arr[p1++];
        else
            tmpArr[cnt] = arr[p2++];
        ++cnt;
    }
    if (p1 <= mid)
        while (p1 <= mid)
        {
            tmpArr[cnt] = arr[p1++];
            ++cnt;
        }
    if (p2 <= right)
        while (p2 <= right)
        {
            tmpArr[cnt] = arr[p2++];
            ++cnt;
        }
    for (int i = left; i <= right; ++i)
        arr[i] = tmpArr[i];
}

void MergeSort(int left, int right, int arrSize)
{
    if (left == right)
        return;
    int mid = (left + right) / 2;
    MergeSort(left, mid, arrSize);
    MergeSort(mid + 1, right, arrSize);
    merge(left, right, mid);
}

int main()
{
    int arrSize = 15;
    int numRange = 50;
    generateArr(arrSize, numRange);
    traverseArr(arrSize);
    MergeSort(0, arrSize - 1, arrSize);
    traverseArr(arrSize);
    return 0;
}