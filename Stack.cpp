 #include<bits/stdc++.h>
using namespace std;
#define el "\n"
 void FOI () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 template<class t>
  class StackADT{
   private:
   t*stack;
   int size;
   int top;
   public:
   StackADT(int size){
      if(size<=0){
         cout << "invalid size" << "\n";
         return ;
      }
      this->size = size;
      top = -1;
      stack = new t[size];
   }
   bool IsEmpty(){
      return (top == -1);
   }
   bool IsFull(){
      return (top==size-1);
   }
   void Push(t new_element){
      if(IsFull()){
         cout << "stack overflow" << "\n";
         return ;
      }
      stack[++top] = new_element;
   }
   t Pop(){
      if(IsEmpty()){
         cout << "stack underflow" << "\n";
         return -1 ;
      }
       t x = stack[top];
       top--;
       return x ;
   }
   void Print(){
      if(IsEmpty()){
         return ;
      }
      for(int i= top ; i>=0;i--){
         cout << stack[i] << ' ';
      }
      cout << "\n";
   }
   bool IsBalanced (char* ex){
      if(strlen(ex) ==0) {
         cout << "is empty" << "\n";
         return 0 ;
      }
    for(int i=0 ; ex[i] !='\0' ; i++){
        if(ex[i]=='('){
         Push('(');
        }
        else if (ex[i]==')'){
         if(IsEmpty()){
            return false ;
         }
         else 
         Pop();
        }
    }
    return (IsEmpty()) ;
   }
   bool Isoperand(char & c){
      if(c == '+' || c == '-' || c =='/' || c =='*')
         return false;
         return true;
   }
     t Top(){
     
      return stack[top] ;
     }
     void operator = (StackADT<t>s2){
        s2.top = top ;
        s2.size = size ;
        t*st2 = new t [size];
       for(int i=0 ; i < top ; i++){
           st2[i] = stack[i] ;
       }
     }
  int evalpostfix(char* postfix){
   int x1 , x2 ;
    for(int i = 0 ; i != '\0' ; i++){
        if(Isoperand(postfix[i])){
         Push(postfix[i] - '0');
        }
        else 
        {
           x2 = Pop();
           x1 = Pop();
           switch(postfix[i]){
            case '+' : Push(x1+x2);
            break;
            case '-' : Push(x1-x2);
            break;
            case '*' : Push(x1*x2);
            break;
            case '/' : Push(x1/x2);
            break;
           }
        }
    }
    return stack[top] ;
  }

  void rePlaceofAllEl(t olditem , t newitem = 50){
    if(IsEmpty()){
      cout << "stack is empty" << "\n" ;
      return ;
    }
    for(int i= top ; i>=0;i--){
      if(stack[i] == olditem)
        stack[i] = newitem ;
    }
  }
  void Reverse(){
   if(IsEmpty())
   return ;
    StackADT<int>*s = new StackADT<int>(top+1);
    for(int i = top ; i>=0 ;i--){
      s->Push(stack[i]);
    }
      for(int i = top ;i>=0;i-- ){
       stack[i] = s->stack[i] ;
    }
    delete [] s ;
  }
  int Presedence(char &s ){
   if(s=='*' || s=='/'){
      return 2 ;
   }
   else if (s=='+' || s=='-'){
      return 1 ;
   }

   return 0;
  }
   char* ConverttoPosfix (char* infx){
        char *posfix = new char [strlen(infx)] ;
        int i=0 , j=0;
        while(infx[i] !='\0'){
         if(Isoperand(infx[i])){
            posfix[j++] = infx[i++] ;
         }
         else {
            if(Presedence(infx[i]) > Presedence(stack[top])){
               Push(infx[i++]);
            }
            else 
            {
               posfix[j++] = Pop() ;
            }
         }
        }
        while(!IsEmpty()){
         posfix[j++] = stack[top] ;
         Pop() ;
        }
        posfix[j] = '\0';
        return posfix ;
   }
      char* ConverttoPrefix (char* infx){
       //  Reverse(infx.begin(),infx.end()) ;
        char *prefix = new char [strlen(infx)] ;
        int i=0 , j=0;
        while(infx[i] !='\0'){
         if(Isoperand(infx[i])){
            prefix[j++] = infx[i++] ;
         }
         else {
            if(Presedence(infx[i]) >= Presedence(stack[top])){
               Push(infx[i++]);
            }
            else 
            {

                     prefix[j++] = Pop() ;
            }
         }
        }
        while(!IsEmpty()){
         prefix[j++] = stack[top] ;
         Pop() ;
        }
    
         prefix[j] = '\0';
        return prefix ;
   }
     int evalpretfix(char* prefix){
   int x1 , x2 ;
    for(int i = 0 ; i != '\0' ; i++){
        if(Isoperand(prefix[i])){
         Push(prefix[i] - '0');
        }
        else 
        {
           x1 = Pop();
           x2 = Pop();
           switch(prefix[i]){
            case '+' : Push(x1+x2);
            break;
            case '-' : Push(x1-x2);
            break;
            case '*' : Push(x1*x2);
            break;
            case '/' : Push(x1/x2);
            break;
           }
        }
    }
    return stack[top] ;
  }
      
  ~StackADT(){
   delete [] stack ;
  }
  int Size() {
   return size ;
  }
  };
  void reverseAndSwapParentheses(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; ++i) {
        swap(exp[i], exp[len - i - 1]);
    }
    for (int i = 0; i < len; ++i) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
}
  char* reverseFinalResult(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        swap(exp[i], exp[len - i - 1]);
    }
    return exp;
}
bool isEmpty(StackADT<int>&s){
   return s.IsEmpty() ;
}
  void Print(StackADT<int>&s){
   s.Print() ;
  }
  StackADT<int> Merge(StackADT<int>&s1 , StackADT<int>&s2){
   StackADT<int>merged(s1.Size()+s2.Size());
   for(int i=0 ; i < s1.Size() ; i++){
     merged.Push(s1.Top());
     s1.Pop() ;
   }
     for(int i=0 ; i < s2.Size() ; i++){
     merged.Push(s2.Top());
     s2.Pop() ;
   }
   return merged ;
  }

  StackADT<int>reverseStack(StackADT<int>&stack){
    StackADT<int>reversestck(stack.Size()) ;
    for(int i = stack.Size() - 1 ; i>=0 ; i--){
      reversestck.Push(stack.Top()) ;
      stack.Pop() ;
    }
    return reversestck;
  }
    StackADT<int> CloneStack(StackADT<int>&stack) {
    StackADT<int>clone(stack.Size()) ;
    for(int i=0 ; i< stack.Size() ; i++){
      clone.Push(stack.Top()) ;
      stack.Pop() ;
    }
    clone = reverseStack(clone) ;
    return clone ;
  }
 int main(){
  FOI ();
  char ex [] = {'(','(','a','+','b',')',')'};
  StackADT<char>s(strlen(ex)) ;
  bool x = s.IsBalanced(ex);
  if(x)
  cout << "Balanced" << "\n";
  else 
  cout << "not Balanced" << "\n";
  char postfix[] = "35*2-";
  StackADT<char> s2(strlen(postfix));
  cout << s2.evalpostfix(postfix) << "\n";
     int size ;
  //  cin >> size ;
    StackADT<int>*s3 = new StackADT<int>(4);
         s3->Push(10);
         s3->Push(20);
         s3->Push(30);
         s3->Print() ;
         s3->Reverse();
         s3->Print() ;
         char infx[] = "a+b*c-d/e";
         StackADT<char>*s4 = new StackADT<char>(strlen(infx)) ;
    //   char *posfix = new char [strlen(infx)+1] ;
         cout <<  s4->ConverttoPosfix(infx) << "\n" ;
         delete [] s4;
          reverseAndSwapParentheses(infx) ;
        StackADT<char>*s5 = new StackADT<char>(strlen(infx)) ;
    //   char *posfix = new char [strlen(infx)+1] ; 
          char *pre = new char [strlen(infx)] ;
          pre =  s5->ConverttoPrefix(infx)  ;
           char pre1[] = "+*23/4";
          cout << s2.evalpretfix(pre1) << "\n";
            pre = reverseFinalResult(pre) ;
          cout << pre << "\n" ;
         delete [] s5;
         delete [] pre ;
 }
