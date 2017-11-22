#include<iostream>
const int max_size = 17;
void merge(int arr[],int first, int last,int mid) {
  int tmp_arr[max_size];
  int first1 = first;
  int last1 = mid;
  int first2 = mid + 1;
  int last2 = last;
  int index = first1;
  for(; (first1 <= last1) && (first2 <= last2) ; ++index) {
    if (arr[first1] < arr[first2]) {
      tmp_arr[index] = arr[first1] ;
      ++first1;
    }
    else {
      tmp_arr[index] = arr[first2] ; 
      ++first2;
    }
  }
  for(; first1 <= last1 ; ++first1 , ++index) {
    tmp_arr[index] = arr[first1] ;
  }
  for(; first2 <= last2 ; ++first2, ++index) {
    tmp_arr[index] = arr[first2];
  }
  for(index = first ; index <= last; ++index) {
    arr[index] = tmp_arr[index];
  }
}
void margesort(int arr[], int first, int last) {
  if(first < last) {
    int mid = (first + last) / 2;
    margesort(arr, first, mid);
    margesort(arr, mid + 1, last);
    merge(arr, first, last, mid);
  }  
}

int main() {
  int arr[] = {3,6,5,4,7,8,2,8,9,6,15,4,5,88,21,12,75};
  const int size = sizeof(arr)/sizeof(arr[0]);
   for(int i = 0; i <= size; ++i) {
    std::cout<<arr[i]<<" ";
  }
   std::cout<<std::endl;
  margesort(arr,0,size);
  for(int i = 0; i <= size; ++i) {
    std::cout<<arr[i]<<" ";
  }
}









