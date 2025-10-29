#include <iostream>

 enum  k
{
	numbers,
	operations
};

struct tokenstr{
	k type;
	int value;
   	 char oper;	
};

int factorial( int n) {
    if (n==0 || n==1) return 1;

    int result = 1;

    for (int i = 2; i<=n; i++) {
        result *= i;}
	return result;
}



    
	
int priority (char op) {
    if (op=='+' || op=='-') return 1;
    if (op=='*' || op=='/') return 2;
    if (op=='^') return 3;
    if (op=='!') return 4;
	

    return 0;
}

    

bool cn (char num ){return(num>= '0' && num<='9'); }


int main(){
	while(1){
	char n[255];
	std::cout<< "Enter youre problem: ";
	std::cin>>n;
	//1 6 * 4
	//16(num) *op 4(num)
	tokenstr save[255];
                int j=0;

int output[255];
tokenstr tokens[255], rpn[255];
 int t=0, in=0, u=0 ;
for (int i=0; n[i]!='\0'; i++ ){
       	if (cn (n[i])){
 int value = 0;
while (cn (n[i])){ value = value *10 +(n[i]- '0'); 
	i++;	} i--;
tokens[t++]= {numbers, value,'\0'};
	}

// 5 6 * 9
	else if(n[i]=='+' || n[i]=='-' || n[i]=='*' || n[i]=='/' ||n[i]=='^' || n[i]=='!'|| n[i]=='('|| n[i]==')') {
            tokens[t++] = {operations, 0, n[i]};
}



}
for (int i = 0; i < t; i++) {
            if (tokens[i].type == numbers) {
                rpn[in++] = tokens[i];  
            } else if (tokens[i].type == operations) {
                if (tokens[i].oper == '(') {
                    save[j++] = tokens[i];
                } else if (tokens[i].oper == ')') {
                    while (j > 0 && save[j - 1].oper != '(') {
                        rpn[in++] = save[--j];
                    }
                    j--;  
                } else {
                    
                    while (j > 0 && priority(save[j - 1].oper) >= priority(tokens[i].oper)) {
                        rpn[in++] = save[--j];
                    }
                    save[j++] = tokens[i]; 
                }
            }
        }
	while(j>0 ){
	rpn[in++]=save[--j];
}
 for (int i=0 ; i<in;i++){
 if( rpn[i].type==numbers){
	 std::cout<< rpn[i].value<<" ";
 }

 else{ std::cout<< rpn[i].oper<<" "; } 


 }

 for( int i=0; i<in; i++){
 if( rpn[i].type==numbers) {
 output[u++]=rpn[i].value;}
 else if( rpn[i].type==operations){
	
	 if( rpn[i].oper=='!'){
         int b = output[--u];
        output[u++] = factorial(b);
 } else {

 int b=output[--u]; int a =output[--u];

 int result =0;
 if (rpn[i].oper=='+'){
 result=a+b;
 }

 else if(rpn[i].oper=='*'){
 result=a*b;}

else if(rpn[i].oper=='/'){
 result=a/b;}

else if(rpn[i].oper=='-'){
 result=a-b;}
output[u++]= result;

 }

 }
 }
std::cout<<std::endl<< output[0]<< std::endl;
}
}
