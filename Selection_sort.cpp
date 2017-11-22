#include <iostream>

int indexOfLargest(const int arr[], int size){
  int indexOfMax = 0;
  for (int currentIndex = 1; currentIndex < size; ++currentIndex){
    if(arr[indexOfMax] < arr[currentIndex])
      indexOfMax = currentIndex;
  }
  return indexOfMax;
}

void print (const int arr[], int size){
   for(int i = 0; i < size; ++i){
     std::cout<< arr[i]<<" ";
   }
   std::cout<<std::endl;
 }

void selectionSort(int arr[], int size){
  for (int i = size - 1; i >= 1; --i) {
    int indexOfMax = indexOfLargest( arr, i + 1);
    int temp = arr[indexOfMax];
    arr[indexOfMax] = arr[i];
    arr[i] = temp;
  }
  print(arr,size);
}


int main(){
  int arr[] = {5,4,5,8,9,63,4,7,8,9,12,32,65,6,2};
  const int size = sizeof(arr)/sizeof(arr[0]);
  print(arr,size);
  selectionSort(arr, size);

  return 0;
}
