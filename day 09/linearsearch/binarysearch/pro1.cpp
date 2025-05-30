#include <iostream>
using namespace std;
int binarySearch( int arr[], int size, int key) 
{
    int left = 0, right = size - 1;

    while (left <= right) 
    {
        int mid = ( left + right) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}
int main ()
{
    int arr[] = {2, 5, 10, 15, 20, 25};
    int key = 25;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, size, key);
    if ( result != -1)
    cout << "Element is found at index " << result << endl;
    else
    cout << "Element is not found." << endl;
    return 0;
}