---
title: Binary Tree
layout: page
parent: Notes
---

# Binary Tree

- <https://oi-wiki.org/graph/tree-basic/>

## 二叉链表

- 手动创建一棵二叉树

## DFS: 二叉树 DFS 遍历 (Depth First Search)

### 先序遍历

![](attachments/Pasted%20image%2020241030140720.png)

按照 **根，左，右** 的顺序遍历二叉树。

```cpp
void preorder(BiTree* root) {
  if (root) {
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
  }
}
```

- preorderTraversal
- TreeNode

### 中序遍历

![](attachments/Pasted%20image%2020241030140844.png)

按照 **左，根，右** 的顺序遍历二叉树。

```cpp
void inorder(BiTree* root) {
  if (root) {
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
  }
}
```

### 后序遍历

![](attachments/Pasted%20image%2020241030140934.png)

按照 **左，右，根** 的顺序遍历二叉树。

```cpp
void postorder(BiTree* root) {
  if (root) {
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
  }
}
```

## BFS: 树上 BFS (Breadth First Search)

从树根开始，严格按照层次来访问节点。

BFS 过程中也可以顺便求出各个节点的深度和父亲节点。

### 树的层序遍历

树层序遍历是指按照从根节点到叶子节点的层次关系，一层一层的横向遍历各个节点。根据 BFS 的定义可以知道，BFS 所得到的遍历顺序就是一种层序遍历。但层序遍历要求将不同的层次区分开来，所以其结果通常以二维数组的形式表示。

例如，下图的树的层序遍历的结果是 `[[1], [2, 3, 4], [5, 6]]`（每一层从左向右）。

```cpp
vector<vector<int>> levelOrder(Node* root) {
  if (!root) {
    return {};
  }
  vector<vector<int>> res;
  queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    int currentLevelSize = q.size();  // 当前层的节点个数
    res.push_back(vector<int>());
    for (int i = 0; i < currentLevelSize; ++i) {
      Node* cur = q.front();
      q.pop();
      res.back().push_back(cur->val);
      for (Node* child : cur->children) {  // 把子节点都加入
        q.push(child);
      }
    }
  }
  return res;
}
```

### 二叉树深度

```cpp
void depth(BiTree* root) {
	int l = 0, r = 0;
	if (root) {
		l = depth(root->left);
		r = depth(root->right);
		return (l > r ? : l : r) + 1;
	}
}
```

### 节点 x 的层数

```cpp
```

### 叶子节点的数量

```cpp

```

## 左右子树相互交换

## 删除以 x 为根的子树

---

Last Updated: Wed Oct 30 14:02:39 CST 2024
