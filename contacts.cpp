#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

class contact
{
private:
    char name[30],pno[20],email[20],address[50];
public:
    void addcontact();
    void allcontacts();
    void searchcontact();
    void updatecontact();
    void deletecontact();
    void mainmenu();
};
contact c1;
void contact :: addcontact()
{
    cout<<"Name  :";
    cin>>name;
    cout<<"\nPhone no :";
    cin>>pno;
    cout<<"\nEmail id  :";
    cin>>email;
    cout<<"\nAddress   :";
    cin>>address;
    ofstream fout;
    fout.open("conatcts.txt",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    cout<<"Contact Saved Successfully"<<endl;
}
void contact :: allcontacts()
{
    ifstream fin;
    fin.open("contacts.txt",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
        cout<<"Name    :"<<name<<endl;
        cout<<"Phone no:"<<pno<<endl;
        cout<<"Email id:"<<email<<endl;
        cout<<"Address :"<<address<<endl;
        cout<<endl;
        fin.read((char*)this,sizeof(*this));
    }
    fin.close();
}
void contact :: searchcontact()
{
    int counter=0;
    char user[20];
    cout<<"Enter Name to be Searched"<<endl;
    cin>>user;
    ifstream fin;
    fin.open("contacts.txt",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
        if(!strcmp(user,name))
        {
            cout<<"Name    :"<<name<<endl;
            cout<<"Phone no:"<<pno<<endl;
            cout<<"Email id:"<<email<<endl;
            cout<<"Address :"<<address<<endl;
            counter++;
        }
        fin.read((char*)this,sizeof(*this));
    }
    if(counter==0)
        cout<<" Contact Not Found "<<endl;
    else
        cout<<"Contact Found Successfully"<<endl;
    fin.close();
}
void contact :: updatecontact()
{
    char user[20];int counter=0;
    cout<<"Enter Name of Contact"<<endl;
    cin>>user;
    fstream file;
    file.open("contacts.txt",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(!strcmp(user,name))
        {
                cout<<"\nName  :";
                cin>>name;
                cout<<"\nPhone no :";
                cin>>pno;
                cout<<"\nEmail id  :";
                cin>>email;
                cout<<"\nAddress   :";
                cin>>address;
                file.seekp(-sizeof(*this), ios::cur);
                file.write((char*)this,sizeof(*this));
                counter++;
        }
        file.read((char*)this,sizeof(*this));
    }
    if(counter==0)
        cout<<"Contact not found"<<endl;
    else
        cout<<"\nContact Updated Successfully"<<endl;
    file.close();
}
void contact :: deletecontact()
{
    char user[20];int counter=0;
    cout<<"Enter Name of the Contact"<<endl;
    cin>>user;
    ifstream fin;
    ofstream fout;
    fin.open("contacts.txt",ios::in|ios::binary);
    fout.open("temp.dat",ios::out|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
        if(strcmp(user,name))
        {
          fout.write((char*)this,sizeof(*this));
          counter++;
        }
        fin.read((char*)this,sizeof(*this));
    }
    fin.close();
    fout.close();
    remove("contacts.txt");
    rename("temp.dat","contacts.txt");
    if(counter==0)
      cout<<"Contact not found"<<endl;
    else
      cout<<"Contact Deleted Successfully"<<endl;
}
void contact :: mainmenu()
{
    int ch;
    do
    {
        cout<<"1. Add New Contact"<<endl;
        cout<<"2. Show All Contacts"<<endl;
        cout<<"3. Search a Contact"<<endl;
        cout<<"4. Delete a Contact"<<endl;
        cout<<"5. Update a Contact"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"\n\nEnter Choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                {
                    c1.addcontact();
                    cout<<"Press enter key to continue...."<<endl;
                    cin.ignore();
                    cin.get();
                    system("cls");
                    break;
                }
            case 2:
                {
                    c1.allcontacts();
                    cout<<"Press enter key to continue...."<<endl;
                    cin.ignore();
                    cin.get();
                    system("cls");
                    break;
                }
            case 3:
                {
                    c1.searchcontact();
                    cout<<"Press enter key to continue...."<<endl;
                    cin.ignore();
                    cin.get();
                    system("cls");
                    break;
                }
            case 4:
                {
                    c1.deletecontact();
                    cout<<"Press any key to continue...."<<endl;
                    cin.ignore();
                    cin.get();
                    system("cls");
                    break;
                }
            case 5:
                {
                    c1.updatecontact();
                    cout<<"Press any key to continue...."<<endl;
                    cin.ignore();
                    cin.get();
                    system("cls");
                    break;
                }
            case 6: break;
            default:
                {
                    cout<<"Enter a Valid option"<<endl;
                    break;
                }
        }

    }while(ch!=6);
}

int main()
{
    c1.mainmenu();
    return 0;
}
