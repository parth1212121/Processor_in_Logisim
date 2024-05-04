#include <bits/stdc++.h>
using namespace std;

map<string,pair<string,int> > m;

string get_12bit_int( int n ){
    string s="";
    if(n<0){
        n=-n;
        vector<int> re;
        for(int i=0;i<12;i++){
            re.push_back(1-n%2);
            n=n/2;
        }
        int c=1;
        for(int i=0;i<12;i++){
            int temp=re[i];
            re[i]=(re[i]+c)%2;
            c=(temp+c)-(temp+c)%2;
        }
        for(int i=0;i<12;i++){
            s=char(re[i]+'0')+s;
        }
    

    }
    else{
        
        for(int i=0;i<12;i++){
            s=char((n%2)+'0')+s;
            n=n/2;
        }
    }
    
    return s;
}
string add(string x3 , string x1 , string x2){

    return "0000000"+m[x2].first+m[x1].first+"000"+m[x3].first+"0110011";
}
string sub(string x3 , string x1 , string x2){
    return "0100000"+m[x2].first+m[x1].first+"000"+m[x3].first+"0110011";
}

string sll(string x3 , string x1 , string x2){
    return "0000000"+m[x2].first+m[x1].first+"001"+m[x3].first+"0110011";
}

string slt(string x3 , string x1 , string x2){
    return "0000000"+m[x2].first+m[x1].first+"010"+m[x3].first+"0110011";
}
string sltu(string x3 , string x1 , string x2){
    return "0000000"+m[x2].first+m[x1].first+"011"+m[x3].first+"0110011";
}
string Xor(string x3 , string x1 , string x2){
    return "0000000"+m[x2].first+m[x1].first+"100"+m[x3].first+"0110011";
}
string srl(string x3 , string x1 , string x2){
    return "0000000"+m[x2].first+m[x1].first+"101"+m[x3].first+"0110011";
}
string Or(string x3 , string x1 , string x2){
    return "0000000"+m[x2].first+m[x1].first+"110"+m[x3].first+"0110011";
}
string And(string x3 , string x1 , string x2){
    return "0000000"+m[x2].first+m[x1].first+"111"+m[x3].first+"0110011";
}

string addi(string x3 , string x1 , int n){

    return get_12bit_int(n)+m[x1].first+"000"+m[x3].first+"0010011";
}
string slti(string x3 , string x1 , int n){

    return get_12bit_int(n)+m[x1].first+"010"+m[x3].first+"0010011";
}
string sltiu(string x3 , string x1 , int n){

    return get_12bit_int(n)+m[x1].first+"011"+m[x3].first+"0010011";
}
string  xori(string x3 , string x1 , int n){

    return get_12bit_int(n)+m[x1].first+"100"+m[x3].first+"0010011";
}
string  ori(string x3 , string x1 , int n){

    return get_12bit_int(n)+m[x1].first+"110"+m[x3].first+"0010011";
}
string  andi(string x3 , string x1 , int n){

    return get_12bit_int(n)+m[x1].first+"111"+m[x3].first+"0010011";
}
string  slli(string x3 , string x1 , int n){

    return get_12bit_int(n)+m[x1].first+"001"+m[x3].first+"0010011";
}
string  srli(string x3 , string x1 , int n){

    return get_12bit_int(n)+m[x1].first+"101"+m[x3].first+"0010011";
}
string lw(string x3 , string x1 , int n){

    return get_12bit_int(n)+m[x1].first+"010"+m[x3].first+"0000011";

} 
string get_substring(int i,int j,string s){
   
    string result="";
    for(int k=i;k<=j;k++){
        result+=s[k];
    }
    return result;
}
string sw(string x2 ,string x1,  int n){
   
    string p=get_12bit_int(n);
    return get_substring(0,6,p)+m[x2].first+m[x1].first+"010"+get_substring(7,11,p)+"0100011";

} 
string get_13bit_int(int n){
    string s="";
    if(n<0){
        n=-n;
        vector<int> re;
        for(int i=0;i<13;i++){
            re.push_back(1-n%2);
            n=n/2;
        }
        int c=1;
        for(int i=0;i<13;i++){
            int temp=re[i];
            re[i]=(re[i]+c)%2;
            c=(temp+c)-(temp+c)%2;
        }
        for(int i=0;i<13;i++){
            s=char(re[i]+'0')+s;
        }
    }
    else{
        
        for(int i=0;i<13;i++){
            s=char((n%2)+'0')+s;
            n=n/2;
        }
    }
    
    return s;
}

string beq( string x1 ,string x2,  int n){
    string p=get_13bit_int(n);
    
    return get_substring(0,0,p)+get_substring(2,7,p)+m[x2].first+m[x1].first+"000"+get_substring(8,11,p)+get_substring(1,1,p)+"1100011";

} 
string convert_string_to_hex(string s){
    string ans="";
    for(int i=0;i<32;i++){
        ans=s[i]+ans;
    }
    string result="";
    for(int i=0;i<8;i++){
        int n=0;
        
        for(int j=0;j<4;j++){
            n+=pow(2,(j))*(ans[i*4+j]-'0');
        }
        if(n<10){
            result=(to_string(n))+result;
        }
        else{
            result=char(int('A')+n-10)+result;
        }
        //cout<<result<<endl;

    }
    return result;
}
int main(int argc, char const *argv[])
{
    m["x0"]=make_pair("00000",0);
    m["x1"]=make_pair("00001",0);
    m["x2"]=make_pair("00010",0);
    m["x5"]=make_pair("00101",0);
    m["x6"]=make_pair("00110",0);
    m["x7"]=make_pair("00111",0);
    m["x8"]=make_pair("01000",0);
    m["x9"]=make_pair("01001",0);
    m["x10"]=make_pair("01010",0);
    //write text into a text file 
    ofstream myfile;
    
    myfile.open("instruction_load.txt");
    
    myfile<<"v2.0 raw\n";
    
        
    myfile<<convert_string_to_hex(addi("x6","x6",1))<<"\n";
    myfile<<convert_string_to_hex(addi("x5","x5",200))<<"\n";
    myfile<<convert_string_to_hex(addi("x7","x7",200))<<"\n";
    myfile<<convert_string_to_hex(sw("x5","x6",8))<<"\n";
    myfile<<convert_string_to_hex(beq("x6","x5",8))<<"\n";
    myfile<<convert_string_to_hex(beq("x5","x7",20))<<"\n";
    
    myfile<<convert_string_to_hex(lw("x7","x6",20))<<"\n";
    myfile<<convert_string_to_hex(addi("x8","x8",100))<<"\n";
    myfile<<convert_string_to_hex(addi("x9","x9",100))<<"\n";
    myfile<<convert_string_to_hex(addi("x10","x10",10))<<"\n";
    myfile<<convert_string_to_hex(addi("x2","x2",4))<<"\n";
    myfile<<convert_string_to_hex(beq("x5","x7",20))<<"\n";
    myfile<<convert_string_to_hex(beq("x5","x7",20))<<"\n";
    myfile<<convert_string_to_hex(beq("x5","x7",20))<<"\n"; 
    myfile<<convert_string_to_hex(add("x7","x6","x5"))<<"\n";
    myfile<<convert_string_to_hex(sub("x7","x6","x5"))<<"\n";
    myfile<<convert_string_to_hex(sw("x8","x2",8))<<"\n";
    myfile<<convert_string_to_hex(sll("x7","x6","x5"))<<"\n";
    myfile<<convert_string_to_hex(slt("x7","x6","x5"))<<"\n";
    myfile<<convert_string_to_hex(sltu("x7","x6","x5"))<<"\n";
    myfile<<convert_string_to_hex(Xor("x7","x6","x5"))<<"\n";
    myfile<<convert_string_to_hex(srl("x7","x6","x5"))<<"\n";
    myfile<<convert_string_to_hex(Or("x7","x6","x5"))<<"\n";
    myfile<<convert_string_to_hex(And("x7","x6","x5"))<<"\n";
    myfile<<convert_string_to_hex(slti("x7","x6",16))<<"\n";
    myfile<<convert_string_to_hex(sltiu("x7","x6",16))<<"\n";
    myfile<<convert_string_to_hex(xori("x7","x6",100))<<"\n";
    myfile<<convert_string_to_hex(ori("x7","x6",100))<<"\n";
    myfile<<convert_string_to_hex(andi("x7","x6",100))<<"\n";
    myfile<<convert_string_to_hex(slli("x7","x6",16))<<"\n";
    myfile<<convert_string_to_hex(srli("x7","x6",16))<<"\n";
    

    
    myfile.close();

    return 0;
}
