/**
System :
   - 20 different specialization
        .each specialization, only 5 spots available (to add patients)
   - patients :
      . to add patients need to:
         (read specialization number [1-20] -
          read name and status (0=regular / 1=urgent)
          . add 5 patients only in each specialization otherwise  not add
          . put urgent patients in the begin of queue and regular at the end.

   - print patients with sorting the status
   - pickup patients
      read specialization number
        .if spec number has patients,
           print the name of patients
           remove patient from the queue
         otherwise print no patient


Test cases ::
1
15 mostafa 0

1
15 asmaa 0

1
15 belal 1

2

1
15 ziad 1

2

1
15 safaa 0

1
15 ashraf 0

2

3
10

3
15

2

1
7 soha 1

2

1
15 amal 1

3
7

2

        .
*/

#include <iostream>
using namespace std;

//Global variables to store the input
int const MAXSPEC=20;
int const MAXQUE=5;

string names[MAXSPEC+1][MAXQUE+1];
int statue[MAXSPEC+1][MAXQUE+1];
int queue_leng[MAXSPEC+1]={0};  // to return how many patients in each specilization
int lenghtofqueu=0;

// to view the list of choices
int choices(){
    cout<<"1) Add new patient\n"
        <<"2) Print all patients\n"
        <<"3) Get next patient\n"
        <<"4) Exit\n";
    // to allow user to put his/her choice
    int ch=0;
    cin>>ch;

    // to check if the input is correct or not
    if ((ch < 1) || (ch > 4)){
        cout<<"Invalid input,Try again.\n";
        choices();
    }
    return ch;
}

// to put urgent case begin of the list
// and regular case last of list

void add_front(int spec, string nam, int val){
      if (val == 1){
       for (int i=lenghtofqueu-1; i>=0; i--){
            names[spec][i+1]=names[spec][i];
            statue[spec][i+1]=statue[spec][i];
       }

       names[spec][0]=nam;
       statue[spec][0]=val;

    }
 }

// function to remove the first element from queue
void remove_patient(int spec){
    for (int i=1; i<=lenghtofqueu; i++){
        names[spec][i-1]=names[spec][i];
        statue[spec][i-1]=statue[spec][i];
    }

    queue_leng[spec]-=1;

}


// to allow user to add new patient
void addPatient(){
    int spec=0;
    string nam=" ";
    int stat=0;

    cout<<"Enter specialization [1-20] : ";
    cin>>spec;

    cout<<"Enter name : ";
    cin>>nam;

    cout<<"Enter statue[0=regular / 1=urgent]: ";
    cin>>stat;

    cout<<endl;

    int length=queue_leng[spec];

    lenghtofqueu=length; // to use it in shift function to know the current size of queue
    if (length < 5){
            names[spec][length]=nam;
            statue[spec][length]=stat;
            queue_leng[spec]+=1;



    // to put urgent case begin of the list
         // and regular case last of list

         add_front(spec, nam ,stat);


    }else{
        // this specialization has not available places to add more patients
        cout<<"Sorry we cannot add more patients for this specialization.\n";

    }




}


// to print list of all patients according to specialization number
void print_ListOfpatients(){

    // to print the list of all patients
    for (int i=0; i<MAXSPEC; i++){
      int le=queue_leng[i];
       if (queue_leng[i] > 0  ){
         cout<<"There are "<<queue_leng[i]<<" patients in specialization "<<i<<endl;
             for (int j=0; j<le; j++){
                  cout<<names[i][j]<<" ";
                     if (statue[i][j] == 0){
                        cout<<"regular"<<endl;
                     }else if(statue[i][j] == 1){
                        cout<<"urgent"<<endl;
                     }
             }
       }
    }


}

// to get next patient
// enter number of specialization
void get_Next(){
    int s=0;
    cout<<"Enter specialization :";
    cin>>s;
    if (queue_leng[s] == 0){
        cout<<"NO patient in this specialization\n";

    }else {
        cout<<names[s][0]<<" you can go to the doctor now.\n";
        // call function to remove this patient from list
        remove_patient(s);
    }



}


// hospital system
void hospital_system(){
    int ch = choices();
    while(true){
       if (ch == 1){
            addPatient();
            cout<<endl;
            ch = choices();
       }else if (ch == 2){
            print_ListOfpatients();
            cout<<endl;
            ch = choices();
       }else if(ch == 3){
            get_Next();
            cout<<endl;
            ch = choices();
       }else if (ch == 4){
            cout<<"See you next time\n";
            break;
       }


    }

}



int main()
{
   hospital_system();

    return 0;
}
