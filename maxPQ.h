#ifndef maxPQ_H
#define maxPQ_H


template<class E, class keyType >
class maxPQ
{
public:
	maxPQ(int size, keyType &k, E &value);
	~maxPQ();

	void insert(E &, keyType &);
	E Remove();



private:
	class item {
	public:
		keyType key;
		E v;
		item() { key = ""; v = 0.0; }
		item(keyType k, E value) { key = k; v = value; };

	};

	int MaxSize;
	int N;
	int heapSize;
	item *a;

	void swap(item &, item &);
	int heapify(int);
	E itemMin;
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }

	void Display2(int, int, int, int);
	void upheap(int k);
	void downheap(int k);
	int IncrementHeapSize() { return ++N; }
};

#endif //PQ