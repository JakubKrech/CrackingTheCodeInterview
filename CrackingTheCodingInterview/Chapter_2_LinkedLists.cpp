#include "Chapter_2_LinkedLists.h"

// EXERCISE 1

int Chapter_2_LinkedLists::Exercise_1_RemoveDups_A(Node* n)
{
    // Time complexity: O(n), but Space complexity: O(n)

    if (!n)
        return 0;

    Node* curr = n;
    map<int, bool> encountered;
    int removedElementsCount = 0;

    encountered[curr->val] = true;

    while (curr->next != nullptr)
    {
        if (encountered.find(curr->next->val) != encountered.end())
        {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete(temp);
            ++removedElementsCount;
        }
        else
        {
            encountered[curr->next->val] = true;
            curr = curr->next;
        }
    }

    return removedElementsCount;
}

int Chapter_2_LinkedLists::Exercise_1_RemoveDups_B(Node* n)
{
    // Approach that does not use hash map, instead it uses two pointers
    // Tradeoff is that Time complexity becomes O(n^2)

    if (!n)
        return 0;

    int removedElements = 0;
    Node* nonDupsPointer = n;

    while (nonDupsPointer->next != nullptr)
    {
        Node* currChecked = nonDupsPointer;

        while (currChecked->next != nullptr)
        {
            if (nonDupsPointer->val == currChecked->next->val)
            {
                Node* temp = currChecked->next;
                currChecked->next = currChecked->next->next;

                cout << "Deleting " << temp->val << endl;

                ++removedElements;
                delete(temp);
            }
            else
            {
                currChecked = currChecked->next;
            }
        }

        if(nonDupsPointer->next != nullptr)
            nonDupsPointer = nonDupsPointer->next;
    }

    return removedElements;
}

// EXERCISE 2

int Chapter_2_LinkedLists::Exercise_2_ReturnKthToLast(Node* n, int k)
{
    if (!n) return -1;

    Node* curr = n;
    int length = 0;

    while (curr != nullptr)
    {
        length += 1;
        curr = curr->next;
    }

    if (k > length)
        return -1;

    int requestedElemIndex = length - k;
    curr = n;

    for (int i = 0; i < requestedElemIndex; ++i)
    {
        if(curr->next != nullptr)
            curr = curr->next;
    }

    return curr->val;
}

// EXERCISE 3

void Chapter_2_LinkedLists::Exercise_3_DeleteMiddleNode(Node* toBeDeleted)
{
    if (!toBeDeleted || !toBeDeleted->next)
        return;

    Node* nextNode = toBeDeleted->next;

    toBeDeleted->val = nextNode->val;
    toBeDeleted->next = nextNode->next;

    delete(nextNode);
}

// EXERCISE 4

Node* Chapter_2_LinkedLists::Exercise_4_Partition(Node* n, int partitionElemValue)
{
    if (!n) return n;

    Node* lastElem = n;

    while (lastElem->next != nullptr)
        lastElem = lastElem->next;

    cout << "LAST ELEM: " << lastElem->val << endl;

    // TODO: zrobic w jednym while dla frontowego oraz srodkowych, jak ponizej

    // move first elem(s) to the back if its partition elem
    while (n != nullptr && n->val == partitionElemValue)
    {
        Node* temp = n;
        n = n->next;

        temp->next = lastElem->next;
        lastElem->next = temp;
    }

    // traverse until lastElem and move partition elements to the back
    Node* curr = n;

    while (curr->next != nullptr && curr->next != lastElem)
    {
        if (curr->next->val == partitionElemValue)
        {
            Node* temp = curr->next;
            curr->next = temp->next;

            temp->next = lastElem->next;
            lastElem->next = temp;
        }
        curr = curr->next;
    }

    // move back pointer past partition elements
    while (lastElem->next != nullptr)
        lastElem = lastElem->next;
    

    // traverse again, and if elem is bigger that partition value, move it to the back
    curr = n;
    while (curr->next != nullptr && curr->val != partitionElemValue)
    {
        if (curr->val > partitionElemValue)
        {
            int tempVal = curr->val;
            
            curr->val = curr->next->val;
            curr->next->val = tempVal;

            Node* temp = curr->next;
            curr->next = curr->next->next;

            temp->next = lastElem->next;
            lastElem->next = temp;
        }
        else
        {
            curr = curr->next;
        }
    }

    return n;
}

// EXERCISE 5

Node* Chapter_2_LinkedLists::Exercise_5_SumLists_ReverseOrder(Node* first, Node* second)
{
    int remaining = 0;

    Node* curr_1 = first;
    Node* curr_2 = second;

    Node* result = nullptr;
    Node* lastDigitResult = result;

    while (curr_1 != nullptr || curr_2 != nullptr)
    {
        int digitSum = remaining;

        if (curr_1)
        {
            digitSum += curr_1->val;
            curr_1 = curr_1->next;
        }
        if (curr_2)
        {
            digitSum += curr_2->val;
            curr_2 = curr_2->next;
        }

        remaining = digitSum / 10;
        digitSum = digitSum % 10;
        Node* resultDigit = new Node(digitSum);

        if (!result)
        {
            result = resultDigit;
            lastDigitResult = result;
        }
        else
        {
            lastDigitResult->next = resultDigit;
            lastDigitResult = resultDigit;
        }
    }

    if (remaining > 0)
    {
        Node* resultDigit = new Node(remaining);
        lastDigitResult->next = resultDigit;
        lastDigitResult = resultDigit;
    }

    return result;
}

Node* Chapter_2_LinkedLists::Exercise_5_SumLists_ForwardOrder(Node* first, Node* second)
{
    Node* reversedFirst = Ex5_ReverseLinkedList(first);
    Node* reversedSecond = Ex5_ReverseLinkedList(second);

    Node* result = Exercise_5_SumLists_ReverseOrder(reversedFirst, reversedSecond);

    return Ex5_ReverseLinkedList(result);
}

// EXERCISE 6

bool Chapter_2_LinkedLists::Exercise_6_Palindrome(Node* n)
{
    map<int, int> occurences;
    int length = 0;
    Node* curr = n;
    bool oddAmmountDetected = false;

    while (curr != nullptr)
    {
        length += 1;
        occurences[curr->val] += 1;

        curr = curr->next;
    }

    if (length == 0)
        return false;

    for (const auto& elem : occurences)
    {
        if (elem.second % 2 != 0)
        {
            if (oddAmmountDetected)
            {
                return false;
            }
            else
            {
                oddAmmountDetected = true;
            }
        }
    }

    return true;
}

// EXERCISE 7

Node* Chapter_2_LinkedLists::Exercise_7_Intersection(Node* first, Node* second)
{
    // minor improvement possible - while calculating length of lists we can also compare
    // last nodes, to check if those lists intersect, if not - return immediately

    int length1 = Ex7_CalculateLinkedListLength(first);
    int length2 = Ex7_CalculateLinkedListLength(second);

    int diff = abs(length1 - length2);

    if (length1 < length2)
    {
        for (int i = 0; i < diff; ++i)
        {
            second = second->next;
        }
    }
    else
    {
        for (int i = 0; i < diff; ++i)
        {
            first = first->next;
        }
    }

    Node* curr1 = first;
    Node* curr2 = second;

    while (curr1 && curr2)
    {
        if (curr1 == curr2)
        {
            return curr1;
        }
        else
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }

    return nullptr;
}

// EXERCISE 8

Node* Chapter_2_LinkedLists::Exercise_8_LoopDetection_A(Node* n)
{
    map<Node*, int> elements;

    Node* curr = n;

    while (curr)
    {
        if (elements.find(curr) != elements.end())
        {
            return curr;
        }
        else
        {
            elements[curr] = 1;
            curr = curr->next;;
        }
    }

    return nullptr;
}

Node* Chapter_2_LinkedLists::Exercise_8_LoopDetection_B(Node* n)
{
    // Approach that does not use hash map, instead it uses
    // two pointers moving at different pace

    Node* slow = n;
    Node* fast = n;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) // loop confirmed
            break;
    }

    if (!fast->next || !fast->next->next)
        return nullptr;

    slow = n;

    // now move slow to the beggining, and move both pointers at the same pace
    // they will meet in the start of the loop
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Helper functions

Node* Chapter_2_LinkedLists::Ex5_ReverseLinkedList(Node* n)
{
    Node* reversed = n;
    n = n->next;
    reversed->next = nullptr;

    while (n != nullptr)
    {
        Node* temp = n->next;
        n->next = reversed;
        reversed = n;
        n = temp;
    }

    return reversed;
}

int Chapter_2_LinkedLists::Ex7_CalculateLinkedListLength(Node* n)
{
    int length = 0;

    Node* curr = n;
    while (curr)
    {
        curr = curr->next;
        length += 1;
    }

    return length;
}
