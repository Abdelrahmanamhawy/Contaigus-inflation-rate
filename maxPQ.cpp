#include "stdafx.h"
#include "maxPQ.h"
#include <iomanip>
template<class E, class keyType>
maxPQ<E, keyType>::maxPQ(int size, keyType &k, E &value) {
	MaxSize = size;
	a = new item[MaxSize + 1];
	N = 0;
	heapSize = 0;
	item *Yarab = new item(k, value);
	a[0] = *Yarab;

}


template <class E, class keyType>
maxPQ<E, keyType>::~maxPQ()
{
	//delete[] a;
}

template <class E, class keyType>
void maxPQ<E, keyType >::insert(E &d, keyType  &key) {

	//No problem here.
	item *tmp = new item(key, d);
	++N;
	a[N] = *tmp;

	for (int i = (N - 1 - 1) >> 1; i >= 0; i--)
	{
		heapify(i);
	}

}




template<class E, class keyType>
E maxPQ<E, keyType>::Remove() {
	item curr = a[1];
	a[1] = a[N--];
	for (int i = (N - 1 - 1) >> 1; i >= 0; i--) {
		heapify(i);
	}


	return curr.v;

}

template<class E, class keyType>
void maxPQ<E, keyType>::downheap(int k) {
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

template<class E, class keyType>
int maxPQ<E, keyType>::heapify(int element_position)
{
	int right_child_position = (element_position + 1) << 1;
	int left_child_position = right_child_position - 1;


	int biggest_element_position = element_position;

	if (a[left_child_position].v > a[biggest_element_position].v && left_child_position<N)
	{
		biggest_element_position = left_child_position;
	}

	if (a[right_child_position].v > a[biggest_element_position].v && right_child_position<N)
	{
		biggest_element_position = right_child_position;
	}

	if (biggest_element_position != element_position)
	{
		swap(a[biggest_element_position], a[element_position]);
		heapify(biggest_element_position);
	}
	return 0;

}

template<class E, class keyType>
void maxPQ<E, keyType> ::swap(item &t1, item &t2) //to swap any two data objects
{
	item temp = t1;
	t1 = t2;
	t2 = temp;
}
#include "stdafx.h"

