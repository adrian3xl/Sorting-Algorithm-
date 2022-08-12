
//Adrian Bailey-1817002262
//AnalysisOfAlgorithms-Module 1 Assignment


#include <iostream>
#include <time.h>
#include <fstream>
#include <cstdlib>

using namespace std;

void swapping(int* pos1, int* pos2)
{
    int temp = *pos1;
    *pos1 = *pos2;
    *pos2 = temp;
}

 void swap(int* pos1, int* pos2) //created for the heapsort
{
    int temp = *pos1;
    *pos1 = *pos2;
    *pos2 = temp;
}

void bubbleSort(int array[], int number) //bubblesort function
{
	int i, j;
	for (i = 0; i < number-1; i++)	
	
 
	for (j = 0; j < number-i-1; j++)
		if (array[j] > array[j+1])
			swapping(&array[j], &array[j+1]);
}



int partition (int array[], int smaller, int larger) 
{
    int pivot = array[larger];  
    int i = (smaller - 1); 
 
    for (int j = smaller; j <= larger - 1; j++)
    {
       
        if (array[j] < pivot)
        {
            i++; 
            swapping(&array[i], &array[j]);
        }
    }
    swapping(&array[i + 1], &array[larger]);
    return (i + 1);
}
 

void quickSort(int array[], int smaller, int larger) //quicksort function
{
    if (smaller < larger)
    {
        
        int partitionindex = partition(array, smaller, larger);
 
       
        quickSort(array, smaller, partitionindex - 1);
        quickSort(array, partitionindex + 1, larger);
    }
}
 
void selectionSort(int array[], int number) 
{ 
    int i, j, min_value; 
  
   
    for (i = 0; i < number-1; i++) 
    { 
         
        min_value = i; 
        for (j = i+1; j < number; j++) 
        if (array[j] < array[min_value]) 
            min_value = j; 
  
       
        swapping(&array[min_value], &array[i]); 
    } 
}  
 
void heapify(int arr[], int n, int i) 
{                                      // Find largest among root, left child and right child   
    int largest = i;  
    int l = 2 * i + 1; 
    int r = 2 * i + 2;  
 
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    
    if (r < n && arr[r] > arr[largest])
        largest = r;    // Swap and continue heapifying if root is not largest   
 
   
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
         
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n) 
{
     
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
         
        swap(arr[0], arr[i]);
 
         
        heapify(arr, i, 0);
    }
}

 
void insertionSort(int array[], int number) //insterionsort function
{
    int i, key, j;
    for (i = 1; i < number; i++)
    {
        key = array[i];
        j = i - 1;
 
       
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}


 
void mergeSort(int array[], int const left_spot, int const middle_spot, int const right_spot) //mergesort function used to merge two sub array
{
    int const sub_arrayOne = middle_spot - left_spot + 1;
    int const sub_arrayTwo = right_spot - middle_spot;
   
    auto *leftArray = new int[sub_arrayOne],
         *rightArray = new int[sub_arrayTwo];
  
     
    for (int i = 0; i < sub_arrayOne; i++)
        leftArray[i] = array[left_spot + i];
    for (int j = 0; j < sub_arrayTwo; j++)
        rightArray[j] = array[middle_spot + 1 + j];
  
    int initialsubarray_indexone = 0,  
        initialsubarray_indextwo = 0;  
    int mergedarray_ofindex = left_spot;  
  
    
    while (initialsubarray_indexone < sub_arrayOne && initialsubarray_indextwo < sub_arrayTwo) {
        if (leftArray[initialsubarray_indexone] <= rightArray[initialsubarray_indextwo]) {
            array[mergedarray_ofindex] = leftArray[initialsubarray_indexone];
            initialsubarray_indexone++;
        }
        else {
            array[mergedarray_ofindex] = rightArray[initialsubarray_indextwo];
            initialsubarray_indextwo++;
        }
        mergedarray_ofindex++;
    }
  
    while (initialsubarray_indexone < sub_arrayOne) {
        array[mergedarray_ofindex] = leftArray[initialsubarray_indexone];
        initialsubarray_indexone++;
        mergedarray_ofindex++;
    }
    
    while (initialsubarray_indextwo < sub_arrayTwo) {
        array[mergedarray_ofindex] = rightArray[initialsubarray_indextwo];
        initialsubarray_indextwo++;
        mergedarray_ofindex++;
    }
}
  
 
void mergeSort(int array[], int const start, int const end) //positioning for subindexes
{
    if (start >= end)
        return;  
  
    int mid = start + (end - start) / 2;
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);
    mergeSort(array, start, mid, end);
}

 
void displayArray(int array[], int number)
{
	int i;
	for (i = 0; i < number; i++)
		cout << array[i] << " ";
	cout << endl;
}





int main() //main of program where everything executes and functions are called respectively 
{
	char cont;
	
	do{
	
	clock_t tStart = clock();
	int size;
	int option;
	int i = 0;
	string filename;
	cout <<endl <<":::::::::::::::::::::::::::::::::::::::::::::::::Welcome:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
cout <<endl <<"\n " << endl;
	cout << "Please enter the number selection (1-3) for Array size : \n";
	cout << "1. Array Size 15000  \n";
	cout << "2. Array Size 65000  \n";
	cout << "3. Array Size 150000  \n";
	cout << "\n";
	cin >> size;

	
	if (size ==1){
	   size = 15000;
	   filename = "C:\\Users\\adria\\Desktop\\Runtime_filelocation\\Mod1\\Record1.txt";
	}
	else if (size ==2){
	    size = 65000;
	    filename = "C:\\Users\\adria\\Desktop\\Runtime_filelocation\\Mod1\\record2.txt";
	}
	 else if (size ==3){
	    size = 150000;
	   filename = "C:\\Users\\adria\\Desktop\\Runtime_filelocation\\Mod1\\Record3.txt";
	}
	
    ifstream input_file(filename.c_str());
    if (!input_file.is_open()) {
        cout << "Error: The file could not be found or or maybe unable to open the file - '"
             << filename << " " << endl;
        return EXIT_FAILURE;
    }

	int number;
	int array[size];
    while (input_file >> number) {
        
        array[i] = number;
        i++;
    }
    
  
 cout <<endl <<":::::::::::::::::::::::::::::::::::::::::::::::::MENU OPTION:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
	    cout<<"1. Bubble Sort" << endl;
	    cout<<"2. Quick Sort" << endl;
	    cout<<"3. Selectiion Sort" << endl;
	    cout<<"4. Heap Sort" << endl;
	    cout<<"5. Insertion Sort" << endl;
	    cout<<"6. Merge Sort" << endl;
	    cout<<"Enter the number of your option:" << endl;
	     cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
	    cin>>option;	
    	
		switch (option)
        {
            case 1:
            {
                bubbleSort(array, size);
    			cout << "Bubble Sorted Array" << endl;
    			displayArray(array, size);
    			break;
            }
            case 2:
            {
               quickSort(array, 0, size - 1);
    		   cout << "Quick Sorted Array" << endl;
    		   displayArray(array, size);
    		   break;
            }
             case 3:
            {
                selectionSort(array, size);
    			cout << "Selection Sorted Array" << endl;
    			displayArray(array, size);
                break;
            }
            case 4:
            {
               heapSort(array,size);
    		   cout << "Heap Sorted Array" << endl;
    		   displayArray(array, size);
    		   break;
            }
             case 5:
            {
                insertionSort(array, size);
    			cout << "Insertion Sorted Array" << endl;
    			displayArray(array, size);
                break;
            }
            case 6:
            {
               mergeSort(array, 0, size - 1);
    		   cout << "Merge Sorted Array" << endl;
    		   displayArray(array, size);
            }
            break;
            default: cout<<"Error: The option selected is not valid" << endl;
        }
        
         //Calculate program execution time
    	int a = 20000, sum=0;
    	for (int i=0; i<a; i++) {
        	for (int k = 0; k<a; k++)
            	sum += 1;}
               
      /*calculate time taken */
    
    printf("Time taken for sort to execute: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  

		
		cout << endl;
    	input_file.close();
		
		cout << "\nDo you want to perform another operation? (y/n)" << endl;
        cin >> cont;
        
	} while (cont == 'y');

    return EXIT_SUCCESS;
}
