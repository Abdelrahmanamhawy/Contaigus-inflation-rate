#include "stdafx.h"
#include "minPQ.h"
#include <iomanip>
template<class E,class keyType>
minPQ<E, keyType>::minPQ(int size,keyType &k,E &value) {
	 MaxSize = size; 
	 a = new item[MaxSize + 1]; 
	 N = 0;
	 heapSize = 0;
	 item *Yarab = new item(k, value);
	 a[0] = *Yarab;
	
}


template <class E, class keyType>
minPQ<E, keyType>::~minPQ()
{
	//delete[] a;
}

template <class E, class keyType>
void minPQ<E, keyType >::insert(E &d, keyType  &key) {

	//No problem here.
	item *tmp = new item(key, d);
	++N;
    a[N] = *tmp;

	for (int i = (N-1 - 1) >> 1; i >= 0; i--){
		heapify(i);
	}
	

}

/*
template<class E,class keyType>
void minPQ<E,keyType>::upheap(int k) {	

	item current = a[k];	

	//MinmeumHeap where parent is smaler than child node.
	while (a[k/2].v>= a[k].v && k!=0) {


		a[k] = a[k / 2];
		k = k / 2;

	}
	cout << "THE VALUE INSERTED IS " << a[k].v << endl;
	cout << "parent:" << setw(2) << a[k / 2].v << endl;
	cout << endl;
	a[k] = current;                               //Stored-perfcetly ! :) 

}
*/
	
	

template<class E,class keyType>
E minPQ<E, keyType>::Remove() {
	item curr = a[1];
	a[1] = a[N--];
	for (int i = (N - 1 - 1) >> 1; i >= 0; i--) {
		heapify(i);
	}


	return curr.v;

}
/*
template<class E,class keyType>
void minPQ<E, keyType>::downheap(int k) {
	int j = 2 * k;
	item last = a[k];
	while (j <= N) {
		if ((j < N) && (a[j].v > a[j + 1].v))
			j++;
		if (last.v <= a[j].v)
			break;
		a[j / 2] = a[j];
		j *= 2;
	}
	a[j / 2] = last;
}
*/

template<class E,class keyType>
int minPQ<E, keyType>::heapify(int element_position)
{
	int right = (element_position + 1) << 1;
	int left = right - 1;


	int smallest_element_position = element_position;

	if (a[left].v < a[smallest_element_position].v && left<N)
	{
		smallest_element_position = left;
	}

	if (a[right].v < a[smallest_element_position].v && right<N)
	{
		smallest_element_position = right;
	}

	if (smallest_element_position != element_position)
	{
		swap(a[smallest_element_position], a[element_position]);
		heapify(smallest_element_position);
	}
	return 0;

}
template<class E,class keyType>
void minPQ<E,keyType> ::swap(item &t1, item &t2) //to swap any two data objects
{
	item temp = t1;
	t1 = t2;
	t2 = temp;
}
// Returns sum of maxium sum subarray in aa[l..h] 
template<class E,class keyType>
int minPQ<E,keyType>:: maxSub( int l, int h)
{

	// Base Case: Only one element 
	if (l == h)
		return a[l].v;

	// Find middle point 
	int m = (l + h) / 2;

	
	return max(maxSub(l, m),
		maxSub( m + 1, h),
		maxSum(l, m, h));
}

template<class E,class keyType>
int minPQ<E, keyType>::maxSum(int l, int m, int h) {
	// Include elements on left of mid. 
	int sum = 0;
	int left_sum = 0;
	for (int i = m; i >= l; i--)
	{
		sum = sum + a[i].v;
		if (sum > left_sum)
			left_sum = sum;
	}

	// Include elements on right of mid 
	sum = 0;
	int right_sum = 0;
	for (int i = m + 1; i <= h; i++)
	{
		sum = sum + a[i].v;
		if (sum > right_sum)
			right_sum = sum;
	}

	// Return sum of elements on left and right of mid 
	return left_sum + right_sum;

}
#include "stdafx.h"

