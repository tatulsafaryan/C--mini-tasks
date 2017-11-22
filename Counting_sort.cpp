#include <iostream>

void print(int arr[], int size){
  for (int i = 0; i < size;  i++ )
  std::cout << arr[i] << " ";
  std::cout <<std::endl;
}

void countingSort(int arr[], int size){
  int min ;
  int max ;
  min = max = arr[0];
  for(int i = 0; i < size; ++i){
    min = (arr[i] < min) ? arr[i] : min;
		max = (arr[i] > max) ? arr[i] : max;
  }
  int sorting_arr_size = max - min + 1;
  int* sorting_arr = new int[sorting_arr_size]{0};

  for(int i = 0; i < size; ++i){
    sorting_arr[arr[i] - min] ++;
  }

  int index = 0;
  for(int i = min; i <= max; ++i){
    for(int j = 0; j < sorting_arr[i - min]; ++j){
      arr[index++] = i;
    }
  }

  print(arr, size);
  delete [] sorting_arr;
}


int main() {
  int arr[] = {5,9,3,9,10,9,2,4,13,10,15,15,2,3,19,20,19,1,0,0};
	const int size = sizeof(arr)/sizeof(arr[0]);
	print(arr,size);
	std::cout << "----------------------"<<std::endl ;
	countingSort(arr, size);
}
