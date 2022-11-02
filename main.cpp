#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>


using namespace std;

class Data;

class Account{
    protected:
    float balance;

    public:

    Account ()
    {
        balance=0;
    }
        Account( float b){

            balance=b;
        }

      Account operator+(Account c)
      {
         Account dd;
         dd.balance= balance+c.balance;
         return dd;
      }

        void displayBal(){

           cout<<"Phone Balance is: "<<balance<<endl;

        }
        friend  void checkk(Account aa,Data mm);
};



class Data{
    protected:
       string fnfStr;
       //string  SuperFnFstr;


    public:
        int ofr;
       void ShowFnF(){

            ifstream iff("fnfbyserial.txt");
            cout<<"Your FnF List: "<<endl;

            if (iff.is_open())cout << iff.rdbuf();


        }
        Data (int of){
        ofr=of;
        }

        virtual void Add(){ }
        virtual void edit(){ }
        virtual void Delete(){ }
        friend  void checkk(Account aa,Data mm);




};




class FnF : public Data{

    public:
        FnF(int a) : Data(a){}


        void Add(){
            ofstream off("fnf.txt", ios:: app);
            ifstream iff("fnfserial.txt");
            int i;
            iff>>i;
            iff.close();

            if(i==0) i++;

            if(i>5){
                cout<<"Your FnF limit is exceed."<<endl;
            }
            else{
                cout<<"Enter the number do you want to add as FnF: ";
                cin>>fnfStr;
                off<<fnfStr<<endl;

                ofstream offff("fnfbyserial.txt" , ios:: app);
                offff<<i<<". "<<fnfStr<<endl;
                offff.close();

                ofstream offf("fnfserial.txt");
                i++;
                offf<<i;
                offf.close();

                off.close();
            }

        }



     void Delete(){

                ShowFnF();
                cout<<"\n"<<endl;
                cout<<"Enter the serial number to delete: ";
                int t;
                cin>>t;


                ifstream ifff("fnfserial.txt");
                int p;
                ifff>>p;
                ifff.close();

                ofstream off("fnfbyserial.txt");
                off<<"";
                off.close();

                ofstream offf("fnfbyserial.txt");
                ifstream iff("fnf.txt");
                string ss;

                for(int i=1; i<p;i++){

                   if(i==t){
                       string ss5;
                       getline(iff,ss5);
                   }
                   else{
                        if(i>t){
                            getline(iff,ss);
                            offf<<i-1<<". "<<ss<<endl;
                            ss.clear();
                        }
                        else{
                            getline(iff,ss);
                            offf<<i<<". "<<ss<<endl;
                            ss.clear();
                        }
                   }
                }

                offf.close();
                iff.close();

                ifstream iiff("fnfbyserial.txt");
                ofstream ooff("fnf.txt");
                string sss;

                for(int i=1;i<p-1;i++){
                    getline(iiff,sss);
                    sss=sss.substr(3,13);
                    ooff<<sss<<endl;
                }

                iiff.close();
                ooff.close();

                ofstream ooofff("fnfserial.txt");
                p--;
                ooofff<<p;
                ooofff.close();





        }

        void edit(){

            int t;
            ShowFnF();
            cout<<"\n"<<endl;

            cout<<"Enter the Serial Number to edit: ";
            cin>>t;


            string sss;

            cout<<"Enter new Number: ";
            cin>>sss;


            ifstream ifff("fnfserial.txt");
            int p;
            ifff>>p;
            ifff.close();


                ofstream offf("fnfbyserial.txt");
                ifstream iff("fnf.txt");
                string ss;

                for(int i=1; i<p;i++){

                   if(i==t){

                       offf<<i<<". "<<sss<<endl;
                       string sssss;
                       getline(iff,sssss);

                   }
                   else{
                            getline(iff,ss);
                            offf<<i<<". "<<ss<<endl;
                            ss.clear();
                    }
                }

                offf.close();
                iff.close();



                ifstream iiff("fnfbyserial.txt");
                ofstream ooff("fnf.txt");
                string sss1;

                for(int i=1;i<p;i++){
                    getline(iiff,sss1);
                    sss1=sss1.substr(3,13);
                    ooff<<sss1<<endl;
                }

                iiff.close();
                ooff.close();



        }
};

void Clearr(){

    ofstream off("fnf.txt");
    ofstream offf("fnfbyserial.txt");
    ofstream offff("fnfserial.txt");

    off<<"";
    offf<<"";
    offff<<0;

    off.close();
    offf.close();
    offff.close();

}

    void checkk(Account aa, Data mm)
    {
       if( aa.balance< mm.ofr)
            cout<<"low balance"<<endl;
       else
        cout<<" you successfully buyed the pack"<<endl;
    }









int main()
{

    Account aa(1003.25);
    Account bb(22.32);
    Account cc;
    cc=aa+bb;
    cc.displayBal();


    int offer;
     cout<<"enter the recired money to buy offer:"<<endl;
    cin>>offer;
    FnF ff(offer);
    Data *dd;
    dd=&ff;



   // Data mm(offer);
    checkk(aa,ff);



    int check=1;




    while(check!=0){
        char ch;

        cout<<"Press a to Add fnf."<<endl;
        cout<<"Press m to edit FnF"<<endl;
        cout<<"Press d to delete Fnf."<<endl;
        cout<<"Press s for show full FnF list"<<endl;
        cout<<"Press e to exit."<<endl;
        cout<<"Press c to clear all records."<<endl;
        cout<<"\n"<<endl;

        cout<<"Your Choice: ";
        cin>>ch;

        cout<<endl;


        if(ch=='a'){

            dd->Add();
        }


        else if(ch=='m'){

            dd->edit();
        }

        else if(ch=='d'){
            dd->Delete();
        }
        else if(ch=='s'){
            int ii;
            ifstream iiiiffff("fnfserial.txt");
            iiiiffff>>ii;
            if(ii==0){
                cout<<"Your fnf list is empty!"<<endl;
            }
            else
           // ff.ShowFnF();
            dd->ShowFnF();
        }

        else if(ch=='e'){
            check=0;
        }
        else if(ch=='c'){
            Clearr();
        }

    }

    return 0;

}
