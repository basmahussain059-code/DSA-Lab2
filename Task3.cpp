#include <iostream>
using namespace std;

class Node
{
public:
    int id;
    Node* next;

    Node(int value)
    {
        id = value;
        next = NULL;
    }
};

class CircularLinkedList
{
private:
    Node* head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }

    void createCircle(int n)
    {
        if(n <= 0)
            return;

        head = new Node(1);
        Node* temp = head;

        for(int i = 2; i <= n; i++)
        {
            temp->next = new Node(i);
            temp = temp->next;
        }

        temp->next = head; // make circular
    }

    void josephus(int k)
    {
        if(head == NULL)
            return;

        Node* curr = head;
        Node* prev = NULL;

        while(curr->next != curr)
        {
            for(int i = 1; i < k; i++)
            {
                prev = curr;
                curr = curr->next;
            }

            cout << "Eliminated Person: "
                 << curr->id << endl;

            prev->next = curr->next;

            Node* del = curr;
            curr = curr->next;

            delete del;
        }

        cout << "\nSurvivor is Person: "
             << curr->id << endl;

        delete curr;
    }
};

int main()
{
    int N, K;

    cout << "Enter Number of People: ";
    cin >> N;

    cout << "Enter Step Count (K): ";
    cin >> K;

    CircularLinkedList circle;

    circle.createCircle(N);

    cout << "\nElimination Order:\n";

    circle.josephus(K);

    return 0;
}