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
    stream>>a; stream>>op1;
    while(stream>>b){
        if((op1=='*')||(op1=='/')){
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
            stream>>op1;
        }
        if((op1=='+')||(op1=='-')){
            if(stream>>op2){
                if((op2=='+')||(op2=='-')){
                    if(op1=='+'){
                        a=a+b;
                    }
                    if(op1=='-'){
                        a=a-b;
                    }
                    op1=op2; op2=0;
                }
                if((op2=='*')||(op2=='/')){
                    while((op2=='*')||(op2=='/')){
                        stream>>c;
                        if(op2=='*'){
                            b=b*c;
                        }
                        if(op2=='/'){
                            if(c!=0){
                                b=b/c;
                            }
                            else{
                                cout<<"ERROR"<<endl;
                                return -1;
                            }
                        }
                        if(!(stream>>op2)){
                            break;
                        }
                    }
                    if(op1=='+'){
                        a+=b;
                    }
                    if(op1=='-'){
                        a-=b;
                    }
                    op1=op2; op2=0;
                }
            }
            else{
                if(op1=='+'){
                    a+=b;
                }
                if(op1=='-'){
                    a-=b;
                }
            }
        }
    }
    cout<<a<<endl;
    return 0;
}
