#pragma once

#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;

void show_arr(int arr[],int size)
{
	for(int i=0;i<size;i++){
		cout<<"\t"<<arr[i];
	}
	cout<<endl;
}

static void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int bubble_sort(int *arr,int size)
{
	assert(arr);
	int flags = 0;
	for(int end = size-1;end > 0;end--){
		int flags = 0;
		for(int i = 0;i<end;i++){
			if(arr[i] > arr[i+1]){
				swap(arr[i],arr[i+1]);
				flags = 1;
			}
		}
		if(flags == 0)
			break;
	}
    return 0;
}

int insert_sort(int *arr,int size)
{
	assert(arr);
//	for(int i = 0;i < size;i++){
//		int j = i;
//		for(;j > 0;j--){
//			if(arr[j+1] < arr[j]){
//				swap(arr[j+1],arr[j]);
//			}else
//				break;
//		}
//	}
    for(int i = 1;i<size;i++){
		int tmp = arr[i];
		int cur = i - 1;
		while(cur >= 0 && tmp < arr[cur]){
			arr[cur+1] = arr[cur];
			--cur;
		}
		arr[cur+1] = tmp;
	}
	return 0;
}

void shell_sort(int *arr,int size)
{
	assert(arr);
    int i,j,gap;
	for(gap = size/2;gap > 0;gap /= 2)
		for(i = 0;i < gap;i++){
			for(j = i+gap; j < size;j+=gap){
				if(arr[j] < arr[j-gap]){
					int tmp = arr[j];
				    int k = j - gap;
					while(k >= 0 && tmp < arr[k]){
						arr[k+gap] = arr[k];
						k -= gap;
					}
					arr[k + gap] = tmp;
				}
			}
		}
}

void shell_sort_1(int arr[].int size)
{
	int j,gap;
	for(gap = size/2;gap > 0;gap /= 2)
		for(j = gap;j<size;j++){
			if(arr[j] < arr[j-gap]){
				int tmp = arr[j];
				int k = j - gap;
				while(k >= 0 && tmp < arr[k]){
					arr[k+gap] = arr[k];
					k -= gap;
				}
				arr[k + gap] = tmp;
			}
		}
}

void shell_sort_2(int arr[],int size)
{
	int gap,i;
	for(gap=size/2;gap > 0;gap /= 2)
		for(i = gap;i < size;i++)
			for(j = i-gap;j>=0 && arr[j] > arr[j+gap];j -= gap)
				swap(arr[j],arr[j+gap]);
}

int select_sort(int *arr,int size)
{
	assert(arr);
//	for(int i = 0;i < size-1;i++){
//		for(int j = i+1;j < size;j++){
//			if(arr[j] < arr[i]){
//				swap(arr[j],arr[i]);
//			}
//		}
//	}
    for(int begin = 0;begin <size-1;++begin){
		int min_index = begin;
		for(int curr_index = begin+1;curr_index < size;++curr_index){
			if(arr[min_index] > arr[curr_index]){
				min_index = curr_index;
			}
		}
		if(min_index != begin){
			swap(arr[min_index],arr[begin]);
		}
	}
	return 0;
}

int select_sort_op(int *arr,int size)
{
	assert(arr);

	int begin = 0;
	int end = size - 1;

	while(begin < end){
		int curr = begin;
		while(curr < end){
			if(arr[curr] < arr[begin]){
				swap(arr[curr],arr[begin]);
			}
			if(arr[curr] > arr[end]){
				swap(arr[curr],arr[end]);
			}
			++curr;
		}
		++begin;
		--end;
	}
	return 0;
}

int heap_sort()
{
	return 0;
}

int get_mid_index(int arr[],int left,int right)
{
	int mid = left + ((right-left)>>1);
	if(arr[left] < arr[right]){
		if(arr[mid] > arr[right]){
			return right;
		}else if(arr[mid] < arr[left]){
			return left;
		}else{
			return mid;
		}
	}else{
		if(arr[mid] > arr[left]){
			return left;
		}else if(arr[mid] < arr[right]){
			return right;
		}else{
			return mid;
		}
	}
}

int partion3(int arr[],int left,int right)
{
	int key_index = get_mid_index(arr,left,right);
	if(key_index != right){
		swap(arr[key_index],arr[right]);
	}
	int key = arr[right];
	int begin = left;
	int end = right;

	while(begin < end){
		while(begin < end && arr[begin] <= key){
			++begin;
		}
		if(begin < end){
			arr[end] = arr[begin];
		}
		while(end > begin && arr[end] >= key){
			--end;
		}
		if(end > begin){
			arr[begin] = arr[end];
		}
	}
	arr[end] = key;
	return begin;
}

int quick_sort(int arr[],int left,int right)
{
	if(left < right){
		int boundary = partion3(arr,left,right);
		quick_sort(arr,left,boundary-1);
		quick_sort(arr,boundary+1,right);
	}
}

