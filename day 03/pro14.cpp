#include <iostream>
using namespace std;
class Teacher{
    public:
    string tname;
    string tdob;
    string tempid;
    string tdept;
    float texp;
    float tsalary;
    
    Teacher(){
        tempid="Un Defined";
        tdept = "Un Assigned";
        texp = 0;
    }
    Teacher(string s_tname,string s_tdob,float s_tsalary){
        tname=s_tname;
        tdob=s_tdob;
        tsalary =s_tsalary;
    }
    Teacher(string s_tname,string s_tdob,float s_tsalary,string s_tempid,string s_tdept,float s_texp){
        tname=s_tname;
        tdob=s_tdob;
        tsalary =s_tsalary;
        tempid=s_tempid;
        tdept = s_tdept;
        texp = s_texp;
    }
    
    Teacher(const Teacher &cy_tch){
        tname=cy_tch.tname;
        tdob=cy_tch.tdob;
        tsalary =cy_tch.tsalary;
        tempid=cy_tch.tempid;
        tdept = cy_tch.tdept;
        texp = cy_tch.texp;
    }
    
    void getTeacherDetails(){
       
        cout<<" | "<<tname<<" | "<<tdob<<" | "<<tdept<<" | "<<tempid<<" | "<<texp<<" | "<<tsalary<<endl;
        
    }
    void setSalary(float s_salary){
        tsalary = s_salary;
    }
    float getSalary(){
        return tsalary;
    }
    
};


int main() {
    
    Teacher t1("Teacher 1","12-05-1990",15000,"CECTH001","CSE",5);
    Teacher t3("Teacher 3","12-05-1990",30000.50,"CECTH003","CSE",2);
    Teacher t4("Teacher 4","12-05-1990",14999,"CECTH004","CSE",7);
    Teacher t5("Teacher 5","12-05-1990",25000.50,"CECTH005","CSE",2);
    Teacher t2=t1;
    cout<<"\n ------ Before Salary Upadte :  Teacher Details --------"<<endl;
    cout<<"|   Name   |  DOB    |   Department    |   Employee ID   |  Experience |    Salary  |"<<endl;
    
    
    
 
    t1.getTeacherDetails();
    t2.getTeacherDetails();
    t3.getTeacherDetails();
    t4.getTeacherDetails();
    t5.getTeacherDetails();
    
    
    cout<<"T1 Salary = "<<t1.getSalary()<<endl;
    cout<<"T2 Salary = "<<t2.getSalary()<<endl;
    cout<<"T3 Salary = "<<t3.getSalary()<<endl;
    cout<<"T4 Salary = "<<t4.getSalary()<<endl;
    cout<<"T5 Salary = "<<t5.getSalary()<<endl;
    
    if (t1.getSalary() <= 15000){
        t1.setSalary(t1.getSalary()*2);
    }else{
        t1.setSalary(t1.getSalary()-5000);
    }
    
    if (t2.getSalary() <= 15000){
        t2.setSalary(t2.getSalary()*2);
    }else{
        t2.setSalary(t2.getSalary()-5000);
    }
    
    if (t3.getSalary() <= 15000){
        t3.setSalary(t3.getSalary()*2);
    }else{
        t3.setSalary(t3.getSalary()-5000);
    }
    
     if (t4.getSalary() <= 15000){
        t4.setSalary(t4.getSalary()*2);
    }else{
        t4.setSalary(t4.getSalary()-5000);
    }
     if (t5.getSalary() <= 15000){
        t5.setSalary(t5.getSalary()*2);
    }else{
        t5.setSalary(t5.getSalary()-5000);
    }
    cout<<"\n\n ------ After Salary Upadte :  Teacher Details --------"<<endl;
    cout<<"T1 Salary = "<<t1.getSalary()<<endl;
    cout<<"T2 Salary = "<<t2.getSalary()<<endl;
    cout<<"T3 Salary = "<<t3.getSalary()<<endl;
    cout<<"T4 Salary = "<<t4.getSalary()<<endl;
    cout<<"T5 Salary = "<<t5.getSalary()<<endl;

    return  0;
}


    