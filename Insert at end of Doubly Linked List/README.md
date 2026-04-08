Algorithm

To insert a new node before a given node in a doubly linked list, start by identifying the previous node of the given node. This is guaranteed because the node to be inserted before is never the head of the list.
Create a new node with the specified value to be inserted before the given node. The back pointer of the new node should point to the previous node, and the next pointer of the new node should point to the given node.
To properly integrate the new node into the list, update the next pointer of the previous node to point to the new node, and set the back pointer of the given node to point to the new node, ensuring the doubly linked list remains intact.
To insert a new node at the end of the doubly linked list, begin by traversing the list from the head node until you reach the tail.
Create a new node with the provided data, setting its back pointer to the current tail node and its next pointer to null, as this new node will become the tail of the list.
Update the next pointer of the current tail node to point to the newly created node, making the new node the new tail of the list.
Finally, return the head of the updated doubly linked list, which remains unchanged after this operation.


🔹 1. Header Files
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <iostream> → used for input/output (cout, cin)
#include <bits/stdc++.h> → includes almost all standard libraries (shortcut)
using namespace std; → avoids writing std:: again and again
🔹 2. Node Class (Doubly Linked List Node)
class Node {
public:
    int data;
    Node* next;
    Node* back;

Each node contains:

data → value stored
next → pointer to next node
back → pointer to previous node

👉 This is what makes it a Doubly Linked List

🔸 Constructors
✔ Constructor with full details
Node(int data1, Node* next1, Node* back1)

Used when you already know:

next node
previous node
✔ Constructor with only data
Node(int data1)
Initializes:
next = nullptr
back = nullptr

👉 Used when creating a new independent node

🔹 3. Convert Array → Doubly Linked List
Node* convertArr2DLL(vector<int> arr)
Step-by-step:
✅ Step 1: Create Head
Node* head = new Node(arr[0]);

👉 First element becomes the head

✅ Step 2: Use prev pointer
Node* prev = head;

👉 Keeps track of the last node created

✅ Step 3: Loop through array
for (int i = 1; i < arr.size(); i++)
✅ Step 4: Create new node
Node* temp = new Node(arr[i], nullptr, prev);

👉 New node:

data = arr[i]
back = prev
next = nullptr
✅ Step 5: Link nodes
prev->next = temp;
prev = temp;

👉 Connection:

prev <--> temp
🔷 Final Structure Example:

For {12, 5, 8}

NULL <- 12 <-> 5 <-> 8 -> NULL
🔹 4. Print Function
void print(Node* head)
Logic:
while (head != nullptr)

👉 Traverse until end

cout << head->data << " ";
head = head->next;

👉 Move forward using next

🔹 5. Insert at Tail
Node* insertAtTail(Node* head, int k)
✅ Step 1: Create new node
Node* newNode = new Node(k);
✅ Step 2: If list is empty
if (head == nullptr)
    return newNode;

👉 New node becomes head

✅ Step 3: Reach last node
Node* tail = head;
while (tail->next != nullptr)
    tail = tail->next;
✅ Step 4: Attach new node
tail->next = newNode;
newNode->back = tail;

👉 Final connection:

tail <--> newNode
🔹 6. Main Function
vector<int> arr = {12, 5, 8, 7, 4};
✅ Convert array → DLL
Node* head = convertArr2DLL(arr);
✅ Print initial list
12 5 8 7 4
✅ Insert at tail
head = insertAtTail(head, 10);
✅ Final Output
12 5 8 7 4 10
🔹 🔥 Visual Flow
Before Insertion:
NULL <- 12 <-> 5 <-> 8 <-> 7 <-> 4 -> NULL
After Insertion:
NULL <- 12 <-> 5 <-> 8 <-> 7 <-> 4 <-> 10 -> NULL
🔹 Time Complexity
Operation	Complexity
Convert Array → DLL	O(n)
Print List	O(n)
Insert at Tail	O(n)

👉 Insert can be optimized to O(1) if we maintain a tail pointer.

🔹 Key Concepts to Remember
Doubly Linked List = two pointers (next + back)
Easy forward + backward traversal
Insertion/deletion is easier than singly linked list






#Code

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node in the list (forward direction)
    Node* back; // Pointer to the previous node in the list (backward direction)

    // Constructor for a Node with both data, next, and back references
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with only data, no next or back references (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    Node* prev = head; // Initialize 'prev' to the head node

    // Traverse the array to create the doubly linked list
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; // Set 'next' of the previous node to the new node
        prev = temp; // Move 'prev' to the new node
    }
    return head;  // Return the head of the doubly linked list
}
// Function to print the elements of the doubly linked list
void print(Node* head) {
    // Traverse through the list and print each node's data
    while (head != nullptr) {
        cout << head->data << " ";  // Print the data of the current node
        head = head->next;          // Move to the next node
    }
}

// Function to insert a new node with value 'k' at the end of the doubly linked list
Node* insertAtTail(Node* head, int k) {
    // Create a new node with data 'k'
    Node* newNode = new Node(k);

    // If the doubly linked list is empty, return the new node as the head
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to the last node of the doubly linked list
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Connect the new node to the last node
    tail->next = newNode;
    newNode->back = tail; // Set the 'back' pointer of the new node to the previous node
    return head;  // Return the head of the modified list
}
int main() {
    // Initialize an array of integers
    vector<int> arr = {12, 5, 8, 7, 4};

    // Convert the array into a doubly linked list
    Node* head = convertArr2DLL(arr);

    // Print the initially created doubly linked list
    cout << "Doubly Linked List Initially: " << endl;
    print(head);

    // Insert a node with value 10 at the end of the doubly linked list
    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
    head = insertAtTail(head, 10);
    print(head);

    return 0;
}
