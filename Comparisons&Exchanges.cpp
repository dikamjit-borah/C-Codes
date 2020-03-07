/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int comparisons = 0;
int exchanges = 0;

void print(int* arr, int size) 
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int &x, int &y)
{
    exchanges++;
    int temp=y;
    y=x;
    x=temp;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element
  
    for (int j = low; j <= high - 1; j++)
    {
        comparisons++;
// If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            comparisons++;
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        comparisons++;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
/* create temp arrays */    
    int L[n1], R[n2];
  
/* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        exchanges++;
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
        exchanges++;
    }
  
/* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        comparisons++;
        if (L[i] <= R[j])
        {
            comparisons++;
            arr[k] = L[i];
            exchanges++;
            i++;
        }
        else
        {
            arr[k] = R[j];
            exchanges++;
            j++;
        }
        k++;    
    }     
  
/* Copy the remaining elements of L[], if there
are any */  
    while (i < n1)
    {
        comparisons++;
        arr[k] = L[i];
        exchanges++;    
        i++;
        k++;
    }
  
/* Copy the remaining elements of R[], if there
are any */  
    while (j < n2)
    {
        comparisons++;
        arr[k] = R[j];
        exchanges++;
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        comparisons++;
        int m = l+(r-l)/2;
  
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
  
        merge(arr, l, m, r);
    }
}
 
int main()
{
    srand(time(NULL));
    int rand();
    int i;
    int array1[1000], array2[1000], array3[1000];
    for( i = 0; i<1000; i++)
    {
        array1[i] = (rand() % 1000) + 1;
    }
    for( i = 0; i<1000; i++)
    {
            array2[i] = (rand() % 1000) + 1;
    }
    for( i = 0; i<1000; i++)
    {
           array3[i] = (rand() % 1000) + 1;
    }     
    cout<<"---For QUICKSORT---"<<endl;
    cout<<"Array FIRST          "<<"    Array SECOND        "<<"    Array THIRD     "<<endl;
    quickSort(array1, 0, 1000);
    int c1 = comparisons;
    int e1 = exchanges;
    comparisons = 0;
    exchanges = 0;
    quickSort(array2, 0, 1000);
    int c2 = comparisons;
    int e2 = exchanges;
    comparisons = 0;
    exchanges = 0;
    quickSort(array3, 0, 1000);
    int c3 = comparisons;
    int e3 = exchanges;
    comparisons = 0;
    exchanges = 0;
    cout<<"Comparisons = "<<c1<<"       Comparisons = "<<c2<<"      Comparisons = "<<c3<<endl;
    cout<<"Exchanges = "<<e1<<"         Exchanges = "<<e2<<"        Exchanges = "<<e3<<endl;
    
    cout<<"---For MERGESORT---"<<endl;
    cout<<"Array FIRST          "<<"    Array SECOND        "<<"    Array THIRD     "<<endl;
    mergeSort(array1, 0, 1000);
    int cm1 = comparisons;
    int em1 = exchanges;
    comparisons = 0;
    exchanges = 0;
    mergeSort(array2, 0, 1000);
    int cm2 = comparisons;
    int em2 = exchanges;
    comparisons = 0;
    exchanges = 0;
    mergeSort(array3, 0, 1000);
    int cm3 = comparisons;
    int em3 = exchanges;
    cout<<"Comparisons = "<<cm1<<"       Comparisons = "<<cm2<<"      Comparisons = "<<cm3<<endl;
    cout<<"Exchanges = "<<em1<<"         Exchanges = "<<em2<<"        Exchanges = "<<em3;
    
    
    
}