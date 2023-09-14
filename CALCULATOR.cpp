#include<iostream>
using namespace std;
class calculator{
    public:
    
    float ADDITION();
    float SUBTRACTION();
    float MULTIPLICATION();
    float DIVISION();
    void operators();
};
 
float calculator :: ADDITION()
{
    float sum;
      // taking input by user
     float data1,data2;
    cout<<"Enter data1"<<endl;
    cin>>data1;
    cout<<"Enter data2"<<endl;
    cin>>data2;
   
   //addition
    sum=data1+data2;
    return sum;
}

float calculator:: SUBTRACTION()
{
    
    // taking input by user
    float data1,data2;
    cout<<"Enter data1"<<endl;
    cin>>data1;
    cout<<"Enter data2"<<endl;
    cin>>data2;

    //subtraction                
    
    return data1-data2;
    // return data2-data1;

}
float calculator:: MULTIPLICATION()
{
    
    // taking input by user
    float data1,data2;
    cout<<"Enter data1"<<endl;
    cin>>data1;
    cout<<"Enter data2"<<endl;
    cin>>data2;

    //subtraction                
    
    return data1*data2;
    // return data2-data1;

}
float calculator:: DIVISION()
{
    
    // taking input by user
    float data1,data2;
    cout<<"Enter data1"<<endl;
    cin>>data1;
    cout<<"Enter data2"<<endl;
    cin>>data2;

    //subtraction                
    
    return data1/data2;
    // return data2-data1;

}

void calculator::operators()
{
     int x;
     
    cout<<"For addition choose 1 "<<endl;
    cout<<"For subtraction choose 2 "<<endl;
    cout<<"For multiplication choose 3 "<<endl;
    cout<<"For division choose 4 "<<endl;
    cout<<"Choose Any number of above"<<endl;
    cin>>x;
    switch (x)
    {
    case 1:
    cout<< "After Additing "<<ADDITION(); 
        /* code */
        break;
    case 2:
    cout<< "After Subtraction "<<SUBTRACTION(); 
    break;
    
    case 3:
    cout<<"After Multiplation"<<MULTIPLICATION();
    break;

    case 4:
    cout<<"After division"<<DIVISION();
    break;
    
    default:
    cout<<"no such type of number is present ";
        break;
    }

}
int main()
{
    calculator C1;
   C1.operators();
   
}


