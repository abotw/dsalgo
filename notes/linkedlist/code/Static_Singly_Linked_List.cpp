// 230525 Static_Singly_Linked_List.cpp

#include <iostream>
using namespace std;

const int N = 100010; // 1e5 + 10
// head:  头指针
// idx:   新节点的地址/下标 // index
// e[N]:  节点值 // element
// ne[N]: 节点的 next 指针 // next element
int head, idx, e[N], ne[N];

// 初始化
void init()
{
		head = -1; // head -> null
		idx = 0; // The array space at index 0 is available.
}

// 将值为 x 的节点插入到头节点/链表头
void add_to_head(int x)
{
		e[idx] = x; // Create a new node with index idx and value x.
		ne[idx] = head; // Change the next pointer of the new node.
		head = idx; // Change the reference of the head pointer.
		idx ++ ; // Move the index idx to the next position.

		//         idx
		//          |
		//          v
		// head -x> O -> O -> O
		//  |       ^
		//  |       |
		//  >>>>>>> x
}

// 将值为 x 的节点插到索引为 k 的节点的后面
void add(int k, int x)
{
		e[idx] = x;
		ne[idx] = ne[k];
		ne[k] = id ++ ;
}

// 将头节点（索引为0的节点）删除，需要保证头节点存在
void del_head()
{
		head = ne[head];
}

// 将索引为 k 的节点的后面的节点删掉
void del(int k)
{
		ne[k] = ne[ne[k]];
}