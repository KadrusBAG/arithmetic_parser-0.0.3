#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string stroka;
    double a, b, c;
    char op1, op2;
    getline(cin, stroka);
    istringstream stream(stroka);
    stream>>a;
    while(stream>>op1){
        if((op1=='*')||(op1=='/')){
            stream>>b;
            if(op1=='*'){
                a=a*b;
            }
            if(op1=='/'){
                if(b!=0){
                    a=a/b;
                }
                else{
                    cout<<"ERROR"<<endl;
                    return -1;
                }
            }
        }
        if((op1=='+')||(op1=='-')){
            while((op2!='*')||(op2!='/')){
                stream>>b; 
                if(!(stream>>op2)){
                    if(op1=='+'){
                        a=a+b;
                    }
                    if(op1=='-'){
                        a=a-b;
                    }
                    break;
                }
                else{
                    if((op2=='+')||(op2=='-')){
                        if(op2=='+'){
                            a+=b; op1=op2;
                        }
                        if(op2=='-'){
                            a-=b; op1=op2;
                        }
                    }
                    if((op2=='*')||(op2=='/')){
                        stream>>c;
                        if(op2=='*'){
                            b=b*c;
                            if(op1=='+'){
                                a=a+b;
                            }
                            if(op1=='-'){
                                a=a-b;
                            }
                        }
                        if(op2=='/'){
                            if(c!=0){
                                b=b/c;
                            }
                            else{
                                cout<<"ERROR"<<endl;
                                return -1;
                            }
                            if(op1=='+'){
                                a=a+b;
                            }
                            if(op1=='-'){
                                a=a-b;
                            }
                        }
                    }
                }
            }
            op2='0';
        }
    }
    cout<<a<<endl;
    return 0;
}
