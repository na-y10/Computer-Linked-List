
#include <iostream>
#include <string>
using namespace std;

struct node
{
    string computerName;
    string ipAddress;
    string macAddress;
    node* next;
};

void CreatList(node* p)
{
    string name, ip, mac;
    node* tmp = NULL;

    for (;;)
    {
        cout << "Enter Computer Name (0 to stop)\n";
        cin >> name;

        if (name == "0")
        {
            if (tmp != NULL)
            {
                delete tmp->next;
                tmp->next = NULL;
            }
            break;
        }
        else
        {
            cout << "Enter IP Address\n";
            cin >> ip;

            cout << "Enter MAC Address\n";
            cin >> mac;

            p->computerName = name;
            p->ipAddress = ip;
            p->macAddress = mac;

            p->next = new node;
            tmp = p;
            p = p->next;
        }
    }
}

int CountList(node* p)
{
    int count = 0;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}

void PrintList(node* p)
{
    while (p != NULL)
    {
        cout << "Computer Name: " << p->computerName << "\t";
        cout << "IP Address: " << p->ipAddress << "\t";
        cout << "MAC Address: " << p->macAddress << endl;
        cout << "========================================\n\n";

        p = p->next;
    }
}

node* isertatbeganing(node* p)
{
    string name, ip, mac;

    cout << "Enter Computer Name you want to insert at beginning:\n";
    cin >> name;

    cout << "Enter IP Address\n";
    cin >> ip;

    cout << "Enter MAC Address\n";
    cin >> mac;

    node* newnode = new node;

    newnode->computerName = name;
    newnode->ipAddress = ip;
    newnode->macAddress = mac;

    newnode->next = p;

    return newnode;
}

void inseratLoc(node* p, string loc)
{
    string name, ip, mac;
    node* temp;

    while (p != NULL && p->computerName != loc)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Not found\n";
        return;
    }

    cout << "Enter Computer Name to insert it:\n";
    cin >> name;

    cout << "Enter IP Address\n";
    cin >> ip;

    cout << "Enter MAC Address\n";
    cin >> mac;

    node* newnode = new node;

    newnode->computerName = name;
    newnode->ipAddress = ip;
    newnode->macAddress = mac;

    temp = p->next;
    p->next = newnode;
    newnode->next = temp;
}

node* DeleteNode(node* p, string key)
{
    node* temp = NULL;
    node* start = p;

    while (p != NULL)
    {
        if (p->computerName == key)
        {
            if (start == p)
                start = p->next;
            else
                temp->next = p->next;

            delete p;
            return start;
        }
        else
        {
            temp = p;
            p = p->next;
        }
    }

    cout << "not found " << key << endl;
    return start;
}

int main()
{
    node* head = new node;
    head->next = NULL;

    string loc, key;
    int choice;
    char Answer = 'y';

    cout << "\n1. To Create List\n";
    cout << "\n2. To Print List\n";
    cout << "\n3. To Count List\n";
    cout << "\n4. To Add at Beginning\n";
    cout << "\n5. To Add at Any Location\n";
    cout << "\n6. To Delete Node\n";
    cout << "======================\n\n";

    while (Answer == 'y' || Answer == 'Y')
    {
        cout << "\nEnter your choice:\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            CreatList(head);
            break;

        case 2:
            cout << "Linked list nodes are:\n";
            PrintList(head);
            break;

        case 3:
            cout << "Number of nodes: " << CountList(head) << endl;
            break;

        case 4:
            head = isertatbeganing(head);
            break;

        case 5:
            cout << "Enter Computer Name you want to insert after it:\n";
            cin >> loc;
            inseratLoc(head, loc);
            break;

        case 6:
            cout << "Enter computer name to delete it:\n";
            cin >> key;
            head = DeleteNode(head, key);
            break;

        default:
            cout << "Invalid choice\n";
        }

        cout << "More? (y/n)\n";
        cin >> Answer;
    }

    return 0;
}
