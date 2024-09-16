#include<iostream>
#include<string>
using namespace std;
struct books
{
    string title;
    string author;
    string subject;
    int bookid;
};

    int main()
{
    books book1 ={"Data Structure", "A" ,"DSA" ,1001 };
    books book2 ={"Database", "B" ,"DBMS" ,2001 };

   cout<< "book1 title :"<<book1.title<<endl;
     cout<< "book1 author :"<<book1.author<<endl;
       cout<< "book1 subject :"<<book1.subject<<endl;
         cout<< "book1 ID :"<<book1.bookid<<endl<<endl<<endl;

   cout<< "book2 title :"<<book2.title<<endl;
     cout<< "book2 author :"<<book2.author<<endl;
       cout<< "book2 subject :"<<book2.subject<<endl;
         cout<< "book2 ID :"<<book2.bookid<<endl<<endl<<endl;
}

