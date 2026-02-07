#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Lib
{
protected:
    string booth;
    char hall;

public:
    Lib(char hall, string booth)
    {
        this->booth = booth;
        this->hall = hall;
    }
};

class Book : public Lib
{
    string title;
    string author;
    int pages;
    int price;

public:
    Book(string title, string author, int pages, int price, char hall, string booth) : Lib(hall, booth)
    {
        this->title = title;
        this->author = author;
        this->pages = pages;
        this->price = price;
    }

    string getTitle()
    {
        return title;
    }
    int getPrice()
    {
        return price;
    }
    int getPages()
    {
        return pages;
    }
    char getHall()
    {
        return hall;
    }
    string getBooth()
    {
        return booth;
    }
    string getAuthor()
    {
        return author;
    }
};

class User
{
    string first_name;
    string last_name;
    string email;
    string phone_number;

public:
    User(string first_name, string last_name, string email, string phone_number)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->email = email;
        this->phone_number = phone_number;
    }

    string getFirstName()
    {
        return first_name;
    }
    string getLastName()
    {
        return last_name;
    }
    string getEmail()
    {
        return email;
    }
    string getPhoneNumber()
    {
        return phone_number;
    }
};

int main()
{
    vector<User *> users;
    vector<Book *> books;

    cout << "\n==================================" << endl;
    cout << "Welcome to \"The LighHouse Library\"" << endl;
    cout << "==================================\n"
         << endl;

    int choice;

    while (true)
    {
        cout << "   ***Main menu***\n";
        cout << "1.Add new user.\n2.Add new book.\n3.View users.\n4.View available books.\n5.Buy a book.\n0.Exit!" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            string first, last, email, number;
            cout << "\nEnter your (fisrt name): ";
            cin >> first;
            cout << "Enter your (last name): ";
            cin >> last;
            cout << "Enter your (email): ";
            cin.ignore();
            getline(cin, email);
            cout << "Enter your (phone number): ";
            cin >> number;

            users.push_back(new User(first, last, email, number));
            cout << "Welcome, " << first << " " << last << "!\n" << endl;
            cout << "============================================================================" << endl;
        }

        else if (choice == 2)
        {
            string title, booth, author;
            int price, pages;
            char hall;
            cout << "\nEnter the book's (title): ";
            getline(cin, title);
            cout << "This book was (wrote by): ";
            getline(cin, author);
            cout << "How many (pages) does \"" << title << "\" has? ";
            cin >> pages;
            cout << "*in dollars* How much does it (costs): ";
            cin >> price;
            cout << "What (hall) and (booth) does \"" << title << "\" belongs? ";
            cin >> hall >> booth;

            books.push_back(new Book(title, author, pages, price, hall, booth));
            cout << "Book added successfully.\n";
            cout << "============================================================================" << endl;
        }

        else if (choice == 3)
        {
            if (users.empty())
                cout << "No users yet." << endl;
            else
            {
                sort(users.begin(), users.end());
                for (int i = 0; i < users.size(); ++i)
                {
                    cout << (i + 1) << "." << users[i]->getFirstName()
                         << " " << users[i]->getLastName()
                         << " | " << users[i]->getEmail()
                         << " | " << users[i]->getPhoneNumber() << endl;
                }
            }
            cout << "============================================================================" << endl;
        }

        else if (choice == 4)
        {
            if (books.empty())
                cout << "No books yet." << endl;
            else
            {
                sort(books.begin(), books.end());
                for (int i = 0; i < books.size(); ++i)
                {
                    cout << (i + 1) << "." << books[i]->getTitle()
                         << " was wrote by: \"" << books[i]->getAuthor()
                         << "\" | " << books[i]->getPages() << "pages ,"
                         << books[i]->getPrice() << "$ | Hall:"
                         << books[i]->getHall() << " ,Booth: "
                         << books[i]->getBooth() << endl;
                }
            }
            cout << "============================================================================" << endl;
        }

        else if (choice == 5)
        {
            int i = 1, book_number;
            Book *selected = books[book_number - 1];
            char answer;
            for (Book *b : books)
            {
                cout << i << "." << b->getTitle() << " ---> " << b->getPrice() << "$" << endl;
                i++;
            }
            cout << "*Number of the book* Which book you want to buy: ";
            cin >> book_number;
            cout << "you will pay " << selected->getPrice() << "$" << "for \"" << selected->getTitle() << "\".\n";
            cout << "Enter \"Y\" to confirm: ";
            cin >> answer;
            if (answer == 'Y' || answer == 'y')
                cout << "You bought the book!";
            else
                cout << "Miser.\n";
            cout << "============================================================================" << endl;
        }

        else if (choice == 0)
            break;
        else
        {
            cout << "Invalid choice!" << endl;
            cout << "============================================================================" << endl;
        }
    }
}