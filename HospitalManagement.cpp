#include <bits/stdc++.h>

using namespace std;


// ================= PATIENT CLASS =================

class Patient {

public:

    int id;
    string name;
    int age;
    string disease;

    Patient(){}

    Patient(int i,string n,int a,string d)
    {
        id=i;
        name=n;
        age=a;
        disease=d;
    }


    void display()
    {
        cout<<"\nPatient ID : "<<id;
        cout<<"\nName       : "<<name;
        cout<<"\nAge        : "<<age;
        cout<<"\nDisease    : "<<disease;
    }
};



// ================= HASH TABLE FOR PATIENT RECORD =================

class PatientHash {


    static const int SIZE=10;

    vector<list<Patient>> table;


    int hashFunction(int id)
    {
        return id%SIZE;
    }


public:


    PatientHash()
    {
        table.resize(SIZE);
    }



    void addPatient(Patient p)
{
    int index = hashFunction(p.id);

    for(auto patient : table[index])
    {
        if(patient.id == p.id)
        {
            cout << "\nPatient ID already exists!";
            return;
        }
    }

    table[index].push_back(p);
    cout << "\nPatient Added Successfully";
}



    void searchPatient(int id)
    {

        int index=hashFunction(id);


        for(auto p:table[index])
        {

            if(p.id==id)
            {
                p.display();
                return;
            }

        }


        cout<<"\nPatient Not Found";

    }



    void deletePatient(int id)
    {

        int index=hashFunction(id);


        for(auto it=table[index].begin();
            it!=table[index].end();
            it++)
        {

            if(it->id==id)
            {

                table[index].erase(it);

                cout<<"\nPatient Deleted";

                return;
            }
        }


        cout<<"\nPatient Not Found";

    }



    void displayAll()
{
    bool found = false;

    for(int i = 0; i < SIZE; i++)
    {
        for(auto p : table[i])
        {
            p.display();
            cout << "\n----------------";
            found = true;
        }
    }

    if(!found)
        cout << "\nNo Patients Found.";
}


};




// ================= DOCTOR BST =================


class Doctor {


public:

    int id;
    string name;
    string specialization;


    Doctor(int i,string n,string s)
    {

        id=i;
        name=n;
        specialization=s;

    }


};



class DoctorNode {


public:

    Doctor data;

    DoctorNode *left;
    DoctorNode *right;


    DoctorNode(Doctor d):data(d)
    {

        left=NULL;
        right=NULL;

    }

};





class DoctorBST {



DoctorNode *root;



DoctorNode* insert(DoctorNode* node,Doctor d)
{

    if(node==NULL)
        return new DoctorNode(d);



    if(d.id < node->data.id)

        node->left=insert(node->left,d);



    else

        node->right=insert(node->right,d);



    return node;

}





void inorder(DoctorNode* node)
{

    if(node==NULL)
        return;


    inorder(node->left);



    cout<<"\nDoctor ID : "
        <<node->data.id;


    cout<<"\nName : "
        <<node->data.name;



    cout<<"\nSpecialization : "
        <<node->data.specialization;


    cout<<"\n----------------";



    inorder(node->right);

}




public:


DoctorBST()
{

    root=NULL;

}



void addDoctor(Doctor d)
{

    root=insert(root,d);


    cout<<"\nDoctor Added";

}




void displayDoctors()
{

    inorder(root);

}



};




// ================= MAIN TEST =================

int main()
{
    PatientHash patients;
    DoctorBST doctors;

    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n   HOSPITAL MANAGEMENT SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Add Patient";
        cout << "\n2. Search Patient";
        cout << "\n3. Delete Patient";
        cout << "\n4. Display All Patients";
        cout << "\n5. Add Doctor";
        cout << "\n6. Display Doctors";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            int id, age;
            string name, disease;

            cout << "\nEnter Patient ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Age: ";
            cin >> age;

            cin.ignore();

            cout << "Enter Disease: ";
            getline(cin, disease);

            patients.addPatient(Patient(id, name, age, disease));

            break;
        }

        case 2:
        {
            int id;

            cout << "\nEnter Patient ID: ";
            cin >> id;

            patients.searchPatient(id);

            break;
        }

        case 3:
        {
            int id;

            cout << "\nEnter Patient ID: ";
            cin >> id;

            patients.deletePatient(id);

            break;
        }

        case 4:
        {
            cout << "\n===== PATIENT LIST =====\n";

            patients.displayAll();

            break;
        }

        case 5:
        {
            int id;
            string name, specialization;

            cout << "\nEnter Doctor ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Doctor Name: ";
            getline(cin, name);

            cout << "Enter Specialization: ";
            getline(cin, specialization);

            doctors.addDoctor(Doctor(id, name, specialization));

            break;
        }

        case 6:
        {
            cout << "\n===== DOCTOR LIST =====\n";

            doctors.displayDoctors();

            break;
        }

        case 7:
        {
            cout << "\nThank You!\n";

            break;
        }

        default:
            cout << "\nInvalid Choice!";
        }

    } while(choice != 7);

    return 0;
}