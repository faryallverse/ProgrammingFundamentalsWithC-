/*
   BS ARTIFICIAL INTELLIGENCE (BAI-A-SP26)
   PF-LAB Semester 01 Project
   Library Management System
   Group A
   Members: Faryal Sarfraz (SP26-BAI-019), Hania Tanveer (SP26-BAI-024), Sharmeen Imtiaz (SP26-BAI-045), and Taha Rizwan (SP26-BAI-049)
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

//  STRUCTURE DEFINITION
struct Book {
    int    serialNumber;
    char   isbn[20];
    char   title[100];
    int    edition;
    char   author[60];
    bool   isReserved;  // 0 = available, 1 = issued/reserved
};

//  CONSTANTS & GLOBALS
const char FILE_NAME[] = "library.txt";

//  FUNCTION PROTOTYPES
void  displayMenu();
void  addBook();
void  deleteBook();
void  searchMenu();
void  searchByISBN();
void  searchByTitle();
void  searchByAuthor();
void  modifyBook();
void  displayAllBooks();
void  issueReserveBook();
void  printBookHeader();
void  printBookRow(const Book* b);
void  pause();

//  MAIN
int main() {
    int choice;

    cout << "\n  ====================================";
    cout << "\n  ||    LIBRARY MANAGEMENT SYSTEM  ||";
    cout << "\n  ||    Dr. Tariq Najmi's Library  ||";
    cout << "\n  ====================================\n";

    do {
        displayMenu();
        cout << "  Enter your choice: ";
        cin  >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addBook();          break;
            case 2: deleteBook();       break;
            case 3: searchMenu();       break;
            case 4: modifyBook();       break;
            case 5: displayAllBooks();  break;
            case 6: issueReserveBook(); break;
            case 7:
                cout << "\n  Thank you for using the Library System. Goodbye!\n\n";
                break;
            default:
                cout << "\n Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

//  MENU
void displayMenu() {
    cout << "\n  ==================================\n";
    cout <<   "  ||         MAIN MENU           ||\n";
    cout <<   "  ==================================\n";
    cout <<   "  |  1. Add New Book             |\n";
    cout <<   "  |  2. Delete Book              |\n";
    cout <<   "  |  3. Search Book              |\n";
    cout <<   "  |  4. Modify/Update Book       |\n";
    cout <<   "  |  5. Display All Books        |\n";
    cout <<   "  |  6. Issue / Reserve a Book   |\n";
    cout <<   "  |  7. Exit                     |\n";
    cout <<   "  ==================================\n";
}

//  Print table header
void printBookHeader() {
    cout << "\n  " << string(95, '-') << "\n";
    cout << "  " << left
         << setw(6)  << "S.No"
         << setw(16) << "ISBN"
         << setw(30) << "Title"
         << setw(5)  << "Ed."
         << setw(25) << "Author"
         << setw(12) << "Status"
         << "\n";
    cout << "  " << string(95, '-') << "\n";
}

//  Print one book row
void printBookRow(const Book* b) {
    cout << "  " << left
         << setw(6)  << b->serialNumber
         << setw(16) << b->isbn
         << setw(30) << b->title
         << setw(5)  << b->edition
         << setw(25) << b->author
         << setw(12) << (b->isReserved ? "Reserved" : "Available")
         << "\n";
}

//  Press Enter to continue
void pause() {
    cout << "\n  Press Enter to continue...";
    cin.get();
}

//  1. ADD NEW BOOK
void addBook() {
    Book newBook;
    newBook.isReserved = false;

    cout << "\n  || ADD NEW BOOK ||\n";
    cout << "  Enter Serial Number: ";
    cin >> newBook.serialNumber;
    cin.ignore();

    cout << "  ISBN : ";
    cin.getline(newBook.isbn, 20);

    cout << "  Title : ";
    cin.getline(newBook.title, 100);

    cout << "  Edition : ";
    cin >> newBook.edition;
    cin.ignore();

    cout << "  Author Name : ";
    cin.getline(newBook.author, 60);

    // Append to text file
    ofstream fout(FILE_NAME, ios::app);
    if (!fout) {
        cout << "\n Error opening file.\n";
        return;
    }
    
    // Write data fields separated by newlines
    fout << newBook.serialNumber << "\n"
         << newBook.isbn << "\n"
         << newBook.title << "\n"
         << newBook.edition << "\n"
         << newBook.author << "\n"
         << newBook.isReserved << "\n";
         
    fout.close();

    cout << "\n Book added successfully! Serial No: " << newBook.serialNumber << "\n";
    pause();
}

//  2. DELETE BOOK
void deleteBook() {
    ifstream fin(FILE_NAME);
    if (!fin) {
        cout << "\n  No records found.\n";
        pause();
        return;
    }

    int targetSerial;
    cout << "\n  || DELETE BOOK ||\n";
    cout << "  Enter Serial Number to delete: ";
    cin  >> targetSerial;
    cin.ignore();

    ofstream fout("temp.txt");
    Book b;
    bool found = false;

    while (fin >> b.serialNumber) {
        fin.ignore();
        fin.getline(b.isbn, 20);
        fin.getline(b.title, 100);
        fin >> b.edition;
        fin.ignore();
        fin.getline(b.author, 60);
        fin >> b.isReserved;
        fin.ignore();

        if (b.serialNumber == targetSerial) {
            found = true;
            cout << "\n  Book found:\n";
            printBookHeader();
            printBookRow(&b);
            cout << "  " << string(95, '-') << "\n";
            cout << "  Confirm delete? (y/n): ";
            char confirm;
            cin >> confirm;
            cin.ignore();
            if (confirm == 'y' || confirm == 'Y') {
                cout << " Book deleted.\n";
                continue; // skip saving it to temp file
            } else {
                cout << " Deletion cancelled.\n";
            }
        }
        
        // Write kept records back to temporary file
        fout << b.serialNumber << "\n" << b.isbn << "\n" << b.title << "\n"
             << b.edition << "\n" << b.author << "\n" << b.isReserved << "\n";
    }

    fin.close();
    fout.close();

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (!found)
        cout << "\n Book with Serial No " << targetSerial << " not found.\n";

    pause();
}

//  3. SEARCH MENU
void searchMenu() {
    int choice;
    cout << "\n  || SEARCH BOOK BY ||\n";
    cout << "  1. ISBN Number\n";
    cout << "  2. Book Title\n";
    cout << "  3. Author Name\n";
    cout << "  Enter choice: ";
    cin  >> choice;
    cin.ignore();

    switch (choice) {
        case 1: searchByISBN();   break;
        case 2: searchByTitle();  break;
        case 3: searchByAuthor(); break;
        default: cout << " Invalid choice.\n";
    }
}

void searchByISBN() {
    ifstream fin(FILE_NAME);
    if (!fin) { cout << "\n No records found.\n"; pause(); return; }

    char key[20];
    cout << "  Enter ISBN to search: ";
    cin.getline(key, 20);

    Book b;
    bool found = false;

    printBookHeader();
    while (fin >> b.serialNumber) {
        fin.ignore();
        fin.getline(b.isbn, 20);
        fin.getline(b.title, 100);
        fin >> b.edition;
        fin.ignore();
        fin.getline(b.author, 60);
        fin >> b.isReserved;
        fin.ignore();

        if (strcmp(b.isbn, key) == 0) {
            printBookRow(&b);
            found = true;
        }
    }
    fin.close();
    if (!found) cout << "  No book found with ISBN: " << key << "\n";
    cout << "  " << string(95, '-') << "\n";
    pause();
}

void searchByTitle() {
    ifstream fin(FILE_NAME);
    if (!fin) { cout << "\n No records found.\n"; pause(); return; }

    char key[100];
    cout << "  Enter Title to search: ";
    cin.getline(key, 100);

    Book b;
    bool found = false;

    printBookHeader();
    while (fin >> b.serialNumber) {
        fin.ignore();
        fin.getline(b.isbn, 20);
        fin.getline(b.title, 100);
        fin >> b.edition;
        fin.ignore();
        fin.getline(b.author, 60);
        fin >> b.isReserved;
        fin.ignore();

        if (strcmp(b.title, key) == 0) {
            printBookRow(&b);
            found = true;
        }
    }
    fin.close();
    if (!found) cout << "  No book found with title: " << key << "\n";
    cout << "  " << string(95, '-') << "\n";
    pause();
}

void searchByAuthor() {
    ifstream fin(FILE_NAME);
    if (!fin) { cout << "\n No records found.\n"; pause(); return; }

    char key[60];
    cout << "  Enter Author Name to search: ";
    cin.getline(key, 60);

    Book b;
    bool found = false;

    printBookHeader();
    while (fin >> b.serialNumber) {
        fin.ignore();
        fin.getline(b.isbn, 20);
        fin.getline(b.title, 100);
        fin >> b.edition;
        fin.ignore();
        fin.getline(b.author, 60);
        fin >> b.isReserved;
        fin.ignore();

        if (strcmp(b.author, key) == 0) {
            printBookRow(&b);
            found = true;
        }
    }
    fin.close();
    if (!found) cout << "  No book found by author: " << key << "\n";
    cout << "  " << string(95, '-') << "\n";
    pause();
}

//  4. MODIFY / UPDATE BOOK
void modifyBook() {
    ifstream fin(FILE_NAME);
    if (!fin) { cout << "\n No records found.\n"; pause(); return; }

    int targetSerial;
    cout << "\n  || MODIFY BOOK ||\n";
    cout << "  Enter Serial Number to modify: ";
    cin  >> targetSerial;
    cin.ignore();

    ofstream fout("temp.txt");
    Book b;
    bool found = false;

    while (fin >> b.serialNumber) {
        fin.ignore();
        fin.getline(b.isbn, 20);
        fin.getline(b.title, 100);
        fin >> b.edition;
        fin.ignore();
        fin.getline(b.author, 60);
        fin >> b.isReserved;
        fin.ignore();

        if (b.serialNumber == targetSerial) {
            found = true;
            cout << "\n  Current Record:\n";
            printBookHeader();
            printBookRow(&b);
            cout << "  " << string(95, '-') << "\n";

            cout << "\n  Enter new details (press Enter to keep current):\n";
            char temp[100];

            cout << "  ISBN [" << b.isbn << "]: ";
            cin.getline(temp, 20);
            if (strlen(temp) > 0) strcpy(b.isbn, temp);

            cout << "  Title [" << b.title << "]: ";
            cin.getline(temp, 100);
            if (strlen(temp) > 0) strcpy(b.title, temp);

            cout << "  Edition [" << b.edition << "]: ";
            cin.getline(temp, 10);
            if (strlen(temp) > 0) {
                b.edition = 0;
                for(int i=0; temp[i] >= '0' && temp[i] <= '9'; i++) {
                    b.edition = b.edition * 10 + (temp[i] - '0');
                }
            }

            cout << "  Author [" << b.author << "]: ";
            cin.getline(temp, 60);
            if (strlen(temp) > 0) strcpy(b.author, temp);

            cout << "\n Book updated successfully.\n";
        }
        
        fout << b.serialNumber << "\n" << b.isbn << "\n" << b.title << "\n"
             << b.edition << "\n" << b.author << "\n" << b.isReserved << "\n";
    }

    fin.close();
    fout.close();
    
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (!found) cout << "\n Book with Serial No " << targetSerial << " not found.\n";
    pause();
}

//  5. DISPLAY ALL BOOKS
void displayAllBooks() {
    ifstream fin(FILE_NAME);
    if (!fin) { cout << "\n No records found.\n"; pause(); return; }

    Book b;
    int count = 0;

    cout << "\n  || ALL BOOKS ||";
    printBookHeader();

    while (fin >> b.serialNumber) {
        fin.ignore();
        fin.getline(b.isbn, 20);
        fin.getline(b.title, 100);
        fin >> b.edition;
        fin.ignore();
        fin.getline(b.author, 60);
        fin >> b.isReserved;
        fin.ignore();

        printBookRow(&b);
        count++;
    }
    fin.close();

    cout << "  " << string(95, '-') << "\n";
    cout << "  Total Books: " << count << "\n";
    pause();
}

//  6. ISSUE / RESERVE A BOOK
void issueReserveBook() {
    ifstream fin(FILE_NAME);
    if (!fin) { cout << "\n No records found.\n"; pause(); return; }

    int targetSerial;
    cout << "\n  || ISSUE / RESERVE BOOK ||\n";
    cout << "  Enter Serial Number: ";
    cin  >> targetSerial;
    cin.ignore();

    ofstream fout("temp.txt");
    Book b;
    bool found = false;

    while (fin >> b.serialNumber) {
        fin.ignore();
        fin.getline(b.isbn, 20);
        fin.getline(b.title, 100);
        fin >> b.edition;
        fin.ignore();
        fin.getline(b.author, 60);
        fin >> b.isReserved;
        fin.ignore();

        if (b.serialNumber == targetSerial) {
            found = true;
            cout << "\n  Book: " << b.title << " by " << b.author << "\n";
            cout << "  Current Status: " << (b.isReserved ? "Reserved/Issued" : "Available") << "\n\n";

            if (b.isReserved) {
                cout << "  This book is currently reserved. Return it? (y/n): ";
                char c; cin >> c; cin.ignore();
                if (c == 'y' || c == 'Y') {
                    b.isReserved = false;
                    cout << " Book returned. Status: Available\n";
                } else {
                    cout << " No changes made.\n";
                }
            } else {
                cout << "  Issue or Reserve this book? (y/n): ";
                char c; cin >> c; cin.ignore();
                if (c == 'y' || c == 'Y') {
                    b.isReserved = true;
                    cout << " Book issued/reserved successfully.\n";
                } else {
                    cout << " No changes made.\n";
                }
            }
        }
        
        fout << b.serialNumber << "\n" << b.isbn << "\n" << b.title << "\n"
             << b.edition << "\n" << b.author << "\n" << b.isReserved << "\n";
    }

    fin.close();
    fout.close();
    
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (!found) cout << "\n Book with Serial No " << targetSerial << " not found.\n";
    pause();
}
