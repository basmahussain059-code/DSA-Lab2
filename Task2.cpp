#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
    int bit;
    Node* next;
    Node* prev;

    Node(int b)
    {
        bit = b;
        next = NULL;
        prev = NULL;
    }
};

class BinaryDLL
{
private:
    Node* head;
    Node* tail;

public:

    BinaryDLL()
    {
        head = NULL;
        tail = NULL;
    }

    void insertEnd(int b)
    {
        Node* newNode = new Node(b);

        if(head == NULL)
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void storeBinary(string binary)
    {
        head = tail = NULL;

        for(int i = 0; i < binary.length(); i++)
        {
            insertEnd(binary[i] - '0');
        }
    }

    void display()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->bit;
            temp = temp->next;
        }

        cout << endl;
    }

    void onesComplement()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            if(temp->bit == 0)
                temp->bit = 1;
            else
                temp->bit = 0;

            temp = temp->next;
        }
    }

    void twosComplement()
    {
        onesComplement();

        Node* temp = tail;
        int carry = 1;

        while(temp != NULL && carry)
        {
            int sum = temp->bit + carry;

            temp->bit = sum % 2;
            carry = sum / 2;

            temp = temp->prev;
        }

        if(carry)
        {
            Node* newNode = new Node(1);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    int toDecimal()
    {
        int decimal = 0;

        Node* temp = head;

        while(temp != NULL)
        {
            decimal = decimal * 2 + temp->bit;
            temp = temp->next;
        }

        return decimal;
    }
};

string addBinary(string a, string b)
{
    string result = "";

    int i = a.length() - 1;
    int j = b.length() - 1;

    int carry = 0;

    while(i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if(i >= 0)
            sum += a[i--] - '0';

        if(j >= 0)
            sum += b[j--] - '0';

        result = char(sum % 2 + '0') + result;

        carry = sum / 2;
    }

    return result;
}

int main()
{
    BinaryDLL num;

    int choice;
    string binary;
    string b1, b2;
        cout << "\n===== Binary DLL Menu =====\n";
        cout << "1. Store Binary Number\n";
        cout << "2. Display Binary Number\n";
        cout << "3. 1's Complement\n";
        cout << "4. 2's Complement\n";
        cout << "5. Binary Addition\n";
        cout << "6. Convert to Decimal\n";
        cout << "7. Exit\n";
    do
    {
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter Binary Number: ";
            cin >> binary;

            num.storeBinary(binary);
            break;

        case 2:
            cout << "Binary Number: ";
            num.display();
            break;

        case 3:
            num.onesComplement();

            cout << "1's Complement: ";
            num.display();
            break;

        case 4:
            num.twosComplement();

            cout << "2's Complement: ";
            num.display();
            break;

        case 5:

            cout << "Enter First Binary: ";
            cin >> b1;

            cout << "Enter Second Binary: ";
            cin >> b2;

            cout << "Sum = "
                 << addBinary(b1,b2)
                 << endl;
            break;

        case 6:

            cout << "Decimal = "
                 << num.toDecimal()
                 << endl;
            break;

        case 7:
            cout << "Program Ended\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    }while(choice != 7);

    return 0;
}