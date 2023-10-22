#include <iostream>
#include<cstring>

using namespace std;
void printBook(struct Books book);

    struct Books
    {
        char title[50];
        char author[50];
        char subject[50];
        int book_id;
    }book;

int main(){

    Books book1;
    Books book2;

    strcpy(book1.title, "c++ tutorial");
    strcpy(book1.author, "weijunjiang");
    strcpy(book1.subject, "computer science");
    book1.book_id = 000001;

    strcpy(book2.title, "python tutorial");
    strcpy(book2.author, "chenshaohua");
    strcpy(book2.subject, "computer science");
    book2.book_id = 000002;

    printBook(book1);
    printBook(book2);

    return 0;
}


void  printBook(struct Books book){
    cout << "the title : " << book.title << endl;
    cout << "the author : " << book.author << endl;
    cout << "the subject : " << book.subject << endl;
    cout << "the id : " << book.book_id << endl;

}

