#include <iostream>
#include <string>
using namespace std;

class Song
{
public:
    int songID;
    string songName;
    string duration;

    Song* next;
    Song* prev;

    Song(int id, string name, string dur)
    {
        songID = id;
        songName = name;
        duration = dur;
        next = NULL;
        prev = NULL;
    }
};

class Playlist
{
private:
    Song* head;
    Song* current;

public:
    Playlist()
    {
        head = NULL;
        current = NULL;
    }

void addSong(int id, string name, string dr)
    {  // dr is for duration
        Song* newSong = new Song(id, name, dr);

        if(head == NULL)
        {
            head = newSong;
            current = head;
            return;
        }

        Song* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newSong;
        newSong->prev = temp;
    }
    void deleteSong(int id)
    {
        Song* temp = head;
        while(temp != NULL && temp->songID != id)
        {
            temp = temp->next;
        }
        if(temp == NULL)
        {
            cout << "Song not found!\n";
            return;
        }
        if(temp == head)
        {
            head = head->next;
            if(head != NULL)
                head->prev = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            if(temp->next != NULL)
                temp->next->prev = temp->prev;
        }
        delete temp;
        cout << "Song Deleted Successfully!\n";
    }
    void displayForward()
    {
        Song* temp = head;
        cout << "\nPlaylist Forward:\n";
        while(temp != NULL)
        {
            cout << temp->songID << " "
                 << temp->songName << " "
                 << temp->duration << endl;
            temp = temp->next;
        }
    }
    void displayBackward()
    {
        if(head == NULL)
            return;
        Song* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        cout << "\nPlaylist Backward:\n";
        while(temp != NULL)
        {
            cout << temp->songID << " "
                 << temp->songName << " "
                 << temp->duration << endl;

            temp = temp->prev;
        }
    }
    void searchSong(int id)
    {
        Song* temp = head;
        while(temp != NULL)
        {
            if(temp->songID == id)
            {
                cout << "\nSong Found\n";
                cout << "ID: " << temp->songID << endl;
                cout << "Name: " << temp->songName << endl;
                cout << "Duration: " << temp->duration << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Song Not Found!\n";
    }
    void playNext()
    {
        if(current == NULL)
        {
            cout << "Playlist Empty\n";
            return;
        }

        if(current->next != NULL)
        {
            current = current->next;
        }

        cout << "Playing: " << current->songName << endl;
    }

    void playPrevious()
    {
        if(current == NULL)
        {
            cout << "Playlist Empty\n";
            return;
        }

        if(current->prev != NULL)
        {
            current = current->prev;
        }

        cout << "Playing: " << current->songName << endl;
    }

    void reversePlaylist()
    {
        Song* temp = NULL;
        Song* currentNode = head;
        while(currentNode != NULL)
        {
            temp = currentNode->prev;
            currentNode->prev = currentNode->next;
            currentNode->next = temp;
            currentNode = currentNode->prev;
        }
        if(temp != NULL)
        {
            head = temp->prev;
        }
        cout << "Playlist Reversed!\n";
    }
};

int main()
{
    Playlist p;

    int choice;
    int id;
    string name;
    string duration;

    do
    {
        cout << "\n==============================";
        cout << "\n PLAYLIST MANAGEMENT SYSTEM";
        cout << "\n==============================";
        cout << "\n1. Add Song";
        cout << "\n2. Delete Song";
        cout << "\n3. Display Playlist Forward";
        cout << "\n4. Display Playlist Backward";
        cout << "\n5. Search Song";
        cout << "\n6. Play Next Song";
        cout << "\n7. Play Previous Song";
        cout << "\n8. Reverse Playlist";
        cout << "\n9. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "\nEnter Song ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Song Name: ";
            getline(cin, name);

            cout << "Enter Duration (MM:SS): ";
            getline(cin, duration);

            p.addSong(id, name, duration);
            cout << "Song Added Successfully!\n";
            break;

        case 2:
            cout << "\nEnter Song ID to Delete: ";
            cin >> id;

            p.deleteSong(id);
            break;

        case 3:
            p.displayForward();
            break;

        case 4:
            p.displayBackward();
            break;

        case 5:
            cout << "\nEnter Song ID to Search: ";
            cin >> id;

            p.searchSong(id);
            break;

        case 6:
            p.playNext();
            break;

        case 7:
            p.playPrevious();
            break;

        case 8:
            p.reversePlaylist();
            break;

        case 9:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 9);

    return 0;
}