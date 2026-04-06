Doubly Linked List
Doubly Linked Lists,  as the name suggests, allows 2-way traversal by introducing two pointers in each node. This enables seamless traversal in both directions, making them a valuable tool for various advanced data structure applications.


Node* prev : The introduction of the previous pointer is the key change from a singly linked list node. This pointer allows traversal in the backward direction, making it suitable for doubly linked lists.

Constructors: Both constructors have been updated to initialize the new previous pointer. In the first constructor, Node(int data1, Node* next, Node* prev), prev is initialized with the provided value. In the second constructor, Node(int data1), the prev is initialized to nullptr, just like the next.

These changes differentiate the Node class for a doubly linked list, allowing it to maintain bidirectional links between nodes, as opposed to the unidirectional links in a singly linked list node.

🔗 Doubly Linked List - Complete Introduction






📌 What is a Doubly Linked List?

A Doubly Linked List (DLL) is a linear data structure where each node contains:

📦 Data
🔗 Pointer to Next Node
🔙 Pointer to Previous Node

👉 This allows traversal in both directions.

🧠 Node Structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};
🎯 Basic Diagram
        ┌───────────┐      ┌───────────┐      ┌───────────┐
NULL ←  │ Prev | 10 | Next │ Prev | 20 | Next │ Prev | 30 | Next │ → NULL
        └───────────┘ ⇄    └───────────┘ ⇄    └───────────┘
🔍 Detailed Visualization
🔹 Single Node
NULL ← [ Prev | 10 | Next ] → NULL
🔹 Multiple Nodes
NULL ← [NULL | 10 | • ] ⇄ [ • | 20 | • ] ⇄ [ • | 30 | NULL ] → NULL
🔄 Traversal Diagram
👉 Forward Traversal
HEAD → 10 → 20 → 30 → NULL
        (using next pointer)
👉 Backward Traversal
NULL ← 10 ← 20 ← 30 ← TAIL
        (using prev pointer)
⚙️ Operations with Diagrams
🟢 Insertion at Beginning

Before:

NULL ← [10] ⇄ [20] ⇄ [30] → NULL

After inserting 5:

NULL ← [5] ⇄ [10] ⇄ [20] ⇄ [30] → NULL
🔵 Insertion at End

Before:

NULL ← [10] ⇄ [20] → NULL

After inserting 30:

NULL ← [10] ⇄ [20] ⇄ [30] → NULL
🔴 Deletion of a Node

Before deleting 20:

NULL ← [10] ⇄ [20] ⇄ [30] → NULL

After:

NULL ← [10] ⇄ [30] → NULL
💻 Example Code (Traversal)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void printForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node{10, NULL, NULL};
    Node* second = new Node{20, head, NULL};
    head->next = second;

    Node* third = new Node{30, second, NULL};
    second->next = third;

    printForward(head);
}
📊 Advantages

✔ Bidirectional traversal
✔ Easier deletion (no need to track previous manually)
✔ Efficient for complex operations

⚠️ Disadvantages

❌ Extra memory for prev pointer
❌ Slightly complex pointer handling

🧩 Real-Life Applications
🔙 Undo / Redo (Text Editors)
🌐 Browser History
🎵 Music Playlist Navigation
📂 File Navigation Systems
📚 Summary Diagram
        prev        next
         ↑           ↓
NULL ← [10] ⇄ [20] ⇄ [30] → NULL
