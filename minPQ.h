#ifndef minPQ_H
#define minPQ_H


template<class E,class keyType >
class minPQ
{
public:
	minPQ(int size, keyType &k, E &value);
	~minPQ();

	void insert(E &, keyType &);
	E Remove();
	int maxSub(int l, int h);

private:
	class item {
	 public:
		 keyType key;
		 E v;
		 item() { key = ""; v = 0.0; }
		 item(keyType k, E value) { key = k; v = value; };
		 
	};
	
	void swap(item &, item &);

	//The main and most powerful function ! :) 
	int heapify(int);
	int MaxSize;
	int N;
	int heapSize;
	item *a;

	int maxSum(int, int, int);

	E itemMin;
	//Function to find the highest between two integers.
	int max(int a, int b) { return (a > b) ? a : b; }

	//Same function but between 3 integers.
	int max(int a, int b, int c) { return max(max(a, b), c); }

	//Get reference to parent,and childern.
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }

};



#endif //PQ