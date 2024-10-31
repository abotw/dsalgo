---
title: "Lab 2:"
layout: home
parent: Labs
---
# Lab2: 

## Q1: removeSubstring

利用串的基本运算，编写一个算法删除串S1中所有的S2子串。

要求如下：

1. 示例：`S1='abcabc'`，`S2='ab'`，执行后`S1='cc'`
2. S2不能是空串
3. 若S2不是S1的子串，需提示错误信息
4. 提交作业时需包括程序源码和运行结果截图（包含 自拟 测试用例）


https://leetcode.cn/problems/remove-all-occurrences-of-a-substring/description/

### Solution

```cpp
/*
 * File: remove_subtring.cpp
 * Leetcode: https://leetcode.cn/problems/remove-all-occurrences-of-a-substring/description/
 * -------------------------
 * 从字符串 s1 中删除所有的 s2 子串。
 */

#include <iostream>
#include <string>
using namespace std;

/* Function prototypes */
string removeSubstring(string s1, const string &s2);
void erase(string& str, size_t pos, size_t len);
size_t find(const string& str, const string& part);

/* Main program */
int main() {
    string s1, s2;
    
    // Test case 1: s2 is empty
    s1 = "abcdef";
    s2 = "";
    cout << "Test case 1: s2 is empty" << endl;
    cout << "Original s1: " << s1 << endl;
    s1 = removeSubstring(s1, s2);
    cout << "Modified s1: " << s1 << endl;
    
    // Test case 2
    s1 = "abcabc";
    s2 = "ab";
    cout << "\nTest case 2" << endl;
    cout << "Original s1: " << s1 << endl;
    s1 = removeSubstring(s1, s2);
    cout << "Modified s1: " << s1 << endl;
    
    // Test case 3: s2 is not a substring of s1
    s1 = "abcdef";
    s2 = "gh";
    cout << "\nTest case 3: s2 is not a substring of s1" << endl;
    cout << "Original s1: " << s1 << endl;
    s1 = removeSubstring(s1, s2);
    cout << "Modified s1: " << s1 << endl;
    
    // Test case 4
    s1 = "daabcbaabcbc";
    s2 = "abc";
    cout << "\nTest case 4" << endl;
    cout << "Original s1: " << s1 << endl;
    s1 = removeSubstring(s1, s2);
    cout << "Modified s1: " << s1 << endl;
    
    return 0;
}

/*
 * Function: removeSubstring
 * -------------------------
 * Return s1 after removing all occurences of s2 from s1 if s2 is not an empty string
 * and s2 is a substring of s1.
 */
string removeSubstring(string s1, const string& s2) {
    // Check if s2 is an empty string
    if (s2.empty()) {
        cerr << "Error: Substring s2 can not be empty." << endl;
        return s1;
    }
    
    // Find if s2 is a substring of s1
//    size_t pos = s1.find(s2);
    size_t pos = find(s1, s2);
    if (pos == string::npos) {
        cerr << "Error: Substring s2 is not found in s1." << endl;
        return s1;
    }
    // Remove all occurences of s2 from s1
    while ((pos = find(s1, s2)) != string::npos) {
//        s1.erase(pos, s2.size());
        erase(s1, pos, s2.size());
    }
    
    return s1;
}

bool empty(const string& str) {
    if (str.size()) return false;
    return true;
}

size_t find(const string& str, const string& part) {
    if (part.size() == 0 || part.size() > str.size()) return string::npos;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == part[0]) {
            bool flag = true;
            for (size_t j = 0; j < part.size(); j++) {
                if (str[i+j] != part[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
    }
    return string::npos;
}

void erase(string& str, size_t pos, size_t len) {
    size_t i;
    for (i = pos; i < str.size(); i++) {
        str[i] = str[i+len];
    }
    str[i] = '\0';
}
```

```cpp
/*
 * File: remove_substring.cpp
 * --------------------------
 * Usage: Removes all occurrences of a substring (s2) from a string (s1).
 */

#include <iostream>
#include <string>
using namespace std;

/* Function prototypes */
string removeSubstring(string s1, const string &s2);
void erase(string& str, size_t pos, size_t len);
size_t find(const string& str, const string& part);

/* Main program */
int main() {
    string s1, s2;
    
    // Test case 1: s2 is an empty string
    s1 = "abcdef";
    s2 = "";
    cout << "Test case 1: s2 is an empty string" << endl;
    cout << "Original s1: " << s1 << endl;
    s1 = removeSubstring(s1, s2);
    cout << "Modified s1: " << s1 << endl;
    
    // Test case 2: Regular case with multiple occurrences of s2 in s1
    s1 = "abcabc";
    s2 = "ab";
    cout << "\nTest case 2" << endl;
    cout << "Original s1: " << s1 << endl;
    s1 = removeSubstring(s1, s2);
    cout << "Modified s1: " << s1 << endl;
    
    // Test case 3: s2 is not found in s1
    s1 = "abcdef";
    s2 = "gh";
    cout << "\nTest case 3: s2 is not found in s1" << endl;
    cout << "Original s1: " << s1 << endl;
    s1 = removeSubstring(s1, s2);
    cout << "Modified s1: " << s1 << endl;
    
    // Test case 4: Complex case with multiple removals
    s1 = "daabcbaabcbc";
    s2 = "abc";
    cout << "\nTest case 4" << endl;
    cout << "Original s1: " << s1 << endl;
    s1 = removeSubstring(s1, s2);
    cout << "Modified s1: " << s1 << endl;
    
    return 0;
}

/*
 * Function: removeSubstring
 * -------------------------
 * Removes all occurrences of the substring s2 from s1, if s2 is not empty and
 * is present in s1. If s2 is not found, s1 remains unchanged.
 */
string removeSubstring(string s1, const string& s2) {
    // Check if s2 is an empty string
    if (s2.empty()) {
        cerr << "Error: Substring s2 cannot be empty." << endl;
        return s1;
    }
    
    // Check is s2 is a substring from s1
    size_t pos = find(s1, s2);
    if (pos == string::npos) {
        cerr << "Error: Substring s2 is not found in s1." << endl;
        return s1;
    }
    
    // Find and remove all occurrences of s2 from s1
    while ((pos = find(s1, s2)) != string::npos) {
        erase(s1, pos, s2.size());
    }
    
    return s1;
}

/*
 * Function: find
 * --------------
 * A custom implementation of the find function that searches for the
 * substring 'part' in 'str'. Returns the index of the first occurrence,
 * or string::npos if 'part' is not found.
 */
size_t find(const string& str, const string& part) {
    if (part.empty() || part.size() > str.size()) return string::npos;
    
    for (size_t i = 0; i <= str.size() - part.size(); i++) {
        bool match = true;
        for (size_t j = 0; j < part.size(); j++) {
            if (str[i + j] != part[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    return string::npos;
}

/*
 * Function: erase
 * ---------------
 * A custom implementation of the erase function that removes 'len' characters
 * from 'str' starting at position 'pos'. The string is resized accordingly.
 */
void erase(string& str, size_t pos, size_t len) {
    for (size_t i = pos; i < str.size() - len; i++) {
        str[i] = str[i + len];
    }
    str.resize(str.size() - len);  // Resize the string after erasure
}

```

## Q2

设计算法实现删除顺序表中多余重复元素。如：对于顺序表（1，2，3，1，3，4，3， 5），删除第四个元素 1 及第五、第七个元素 3。



## Q3

设计算法，实现在一个递增有序的顺序表的适当位置插入元素 x，使得该顺序表仍然 递增有序。分析算法的时间复杂度

```c
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100

// 数据类型
typedef struct {
    int data[MAXLEN];
    int lastidx;
} seqlist;

// 置空表
void setNull(seqlist* list);
// 初始化顺序表
seqlist* initSeqlist();
// 求表长
int length(seqlist* list);
// 按序号取元素
int get(seqlist* list, int pos);
// 按值取位置
void locate(seqlist* list, int val);
// 判断表满
int isFull(seqlist* list);
// 插入数据
int insert(seqlist* list, int pos, int val);
// 删除数据
int delete(seqlist* list, int pos);
// 打印
void printList(seqlist* list);
// 去重
void deduplication(seqlist* list);
// 保证有序插入
int insertByVal(seqlist* list, int val);

int main() {
    // Q1: 去重
    // init
    seqlist* list1 = initSeqlist();
    // insert
    insert(list1, 1, 1);
    insert(list1, 2, 2);
    insert(list1, 3, 3);
//    insert(list1, 4, 1);
//    insert(list1, 5, 3);
//    insert(list1, 6, 4);
//    insert(list1, 7, 3);
//    insert(list1, 8, 5);
    // test
    printList(list1);
    deduplication(list1);
    // print
    printList(list1);
    
    // Q2: 保证有序插入
    // init
    seqlist* list2 = initSeqlist();
    // insert
    insert(list2, 1, 10);
    insert(list2, 2, 20);
    insert(list2, 3, 30);
    insert(list2, 4, 40);
    insert(list2, 5, 50);
    insert(list2, 6, 60);
    insert(list2, 7, 70);
    insert(list2, 8, 80);
    // test
    printList(list2);
    insertByVal(list2, 40);
    // print
    printList(list2);
    
    return 0;
}

// 初始化
seqlist* initSeqlist() {
    seqlist* list;
    list = malloc(sizeof(seqlist));
    list->lastidx = -1;
    return list;
}

// 置空
void setNull(seqlist* list) {
    list->lastidx = -1;
}

// 表满
int isFull(seqlist* list) {
    if (list->lastidx+1 >= MAXLEN) return 1;
    return 0;
}

// 求表长
int length(seqlist* list) {
    return list->lastidx = 1;
}

// 按序号取元素
int get(seqlist* list, int pos) {
    int val;
    if (pos < 1 || pos > length(list)) {
        printf("ERROR: out of range.");
    } else {
        val = list->data[pos-1];
    }
    return val;
}

// 按值取位置
void locate(seqlist* list, int val) {
    int flag = 0;
    for (int i = 0; i < length(list); i++) {
        if (list->data[i] == val) {
            printf("%d\n", i+1);
        }
    }
    if (!flag) {
        printf("%d\n", -1);
    }
}

// 打印
void printList(seqlist* list) {
    for (int i = 0; i <= list->lastidx; i++) {
        printf("%d\t", list->data[i]);
    }
    puts("");
}

// 删除数据
int delete(seqlist* list, int pos) {
    if (list->lastidx < 0) {
        printf("ERROR: the list is isFull.");
        return 0;
    } else if (pos < 1 || pos > list->lastidx+1) {
        printf("ERROR: pos is invalid.");
        return 0;
    } else {
        for (int i = pos; i <= list->lastidx+1; i++) {
            list->data[i-1] = list->data[i];
        }
        list->lastidx--;
    }
    return 1;
}

// 去重
void deduplication(seqlist* list) {
    for (int i = 0; i <= list->lastidx; i++) {          // [0, i]: 已去重
        for (int j = i+1; j <= list->lastidx; j++) {    // [j=i+1, len): 未去重
            if (list->data[j] == list->data[i]) {       // 若相等
                // 则删除
                for (int k = j; k < list->lastidx; k++) {
                    list->data[k] = list->data[k+1];    // 从后往前挪
                }
                list->lastidx--; // 表长减1
            }
        }
    }
}

// 插入
int insert(seqlist* list, int pos, int val) {
    // 判满
    if (isFull(list)) {
        printf("ERROR: overflow.");
        return 0;
    }
    // 越界
    if (pos < 1 || pos > list->lastidx+2) {
        printf("ERROR: out of range.");
        return 0;
    }
    for (int i = list->lastidx; i >= pos-1; i--) {
        list->data[i+1] = list->data[i];
    }
    list->data[pos-1] = val;
    list->lastidx = list->lastidx + 1;
    return 1;
}

// 保证有序插入
int insertByVal(seqlist* list, int val) {
    for (int i = 0; i <= list->lastidx; i++) {    // 遍历
        if (list->data[i] > val) {               // 找到比 val 大的元素
            insert(list, i+1, val);               // 将 val 插在前面
            return 1;
        }
    }
    insert(list, list->lastidx+2, val);           // 都比 val 小，插到最后
    return 0;
}
```






















































`size_t` 和 `std::string::npos` 是 C++ 标准库中的概念，常用于字符串操作中。接下来我将详细解释它们的作用以及为什么在程序中需要使用它们。

### 1. `size_t`
**`size_t`** 是 C++ 标准库中定义的一种数据类型，主要用于表示非负的大小或索引。

#### 为什么要用 `size_t`？
- **数据类型的适用性**：`size_t` 是专门用来表示内存大小和数组、字符串等**容器**的索引的类型。它通常是一个**无符号整数类型**，适用于表示任何**正整数**，并且由于它的无符号性质，避免了负值带来的问题。
- **平台无关**：`size_t` 是平台无关的，它的具体大小根据操作系统和硬件的不同而变化。例如在32位系统上，它可能是4字节，而在64位系统上，它可能是8字节。通过使用 `size_t`，程序能够在不同的平台上高效、无错误地处理大小和索引。
- **find() 返回类型**：`std::string::find()` 函数返回 `size_t` 类型的值，表示子串首次出现的位置（索引）。因此，使用 `size_t` 来存储这个返回值是最合适的选择。

```cpp
size_t pos = S1.find(S2);
```
- 这里的 `pos` 代表 `S2` 在 `S1` 中首次出现的位置。由于这个值是非负的索引，`size_t` 是合适的类型。

### 2. `std::string::npos`
**`std::string::npos`** 是 `std::string` 类中定义的一个常量，用于表示一个特殊的值，通常表示“未找到”的情况。

#### 为什么要用 `std::string::npos`？
- **表示未找到的子串**：`std::string::find()` 函数在成功找到子串时，返回它的起始索引（`size_t` 类型），而如果没有找到子串，它会返回一个特殊的值：`std::string::npos`。这个值通常是 `size_t` 类型的最大值，比如在32位系统上可能是 `4294967295`，但你不需要关心它的具体数值，只需知道它表示“未找到”即可。
  
```cpp
if (pos == std::string::npos) {
    // Handle error: substring not found
}
```
- 这段代码检查 `S2` 是否在 `S1` 中找到了。如果 `find()` 返回 `std::string::npos`，表示 `S2` 不是 `S1` 的子串，因此触发错误处理逻辑。

### 总结
- **`size_t`**：用于表示字符串或数组的大小或索引，适用于返回非负整数值的函数，确保在处理内存大小、索引时没有负值问题。
- **`std::string::npos`**：用来表示“未找到”的特殊标志，常用于 `find()` 等字符串查找函数的返回值判断。

这两个元素是 C++ 标准库中处理字符串和其他容器时的常见工具，能够提高程序的可移植性和安全性。