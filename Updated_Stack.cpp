   #include<bits/stdc++.h>
    using namespace std;
 #define endl "\n"

 void FOI () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

  template<typename t>
  class StackADT{
    private:
    t *stack1 ;
     int size ;
      int top ;
      public:
       StackADT(int size) {
        this->size = size ;
         stack1 = new t [this->size] ;
         top  -1 ;
       }
       bool IsEmpty() {
        return (top==-1) ;
       }
      bool IsFull() {
        return (top == size - 1) ;
      }
      void Push(t item) {
        if(IsFull()) {
          cout << "stack overflow" << endl;
          return ;
        }
         top++;
          stack1[top] = item ;
      }
      t Pop() {
        if(IsEmpty()) {
          cout << "stack underflow" << endl;
          return t(-1) ;
        }
         t x = stack1[top] ;
         top--;
         return x ;
      }
      void Display() {
        if(IsEmpty()) {
          cout << "stack underflow" << endl;
          return  ;
        }
         for(int i= top ; i>=0;i--) {
          cout << stack1[i] << " " ;
         }
         cout << "\n" ;
      }
      bool IsBalanced(char * ex) {
        for(int i=0 ; ex[i] !='\0' ;i++) {
          if(ex[i]=='(')
           Push('(') ;
           else if (ex[i]==')') {
            if(IsEmpty()) {
              return false;
            }
            else {
              Pop() ;
            }
           }
        }
        return (IsEmpty()) ;
      }
      bool IsOperand(char s) {
        if(s=='*' || s=='/' ||s=='+' ||s=='-')
        return false ;
         return true ;
      }
      int Presedence(char s) {
        if(s=='*' || s=='/')
        return 2;
        else if (s=='+' ||s=='-')
        return 1;
        else
        return 0 ;
      }
    char* ConverToPosfix(char *infix) {
        char* postfix = new char [strlen(infix) + 1]  ; // 1 as '\0'
        int i= 0 , j =0 ;       // i for infix , j for postfix
          while(infix[i] !='\0') {
            if(IsOperand(infix[i])) {
              postfix[j++] = infix[i++] ;
            }
            else {
              if(Presedence(infix[i]) > Presedence(stack1[top]))
                  Push(infix[i++]);
                  else
                   {
                    postfix[j++] = stack1[top] ;
                    Pop() ;
                   }
            }
          }
           while(!IsEmpty()) {
               postfix[j++] = stack1[top] ;
                 Pop() ;
           }
            postfix[j] = '\0' ;
           return postfix ;
    }
     int evalPos(char *postfix) {
           int item1 , item2 ;
       for(int i=0 ; postfix[i]!='\0' ; i++) {
        if(IsOperand(postfix[i])) {
          Push(postfix[i] - '0') ;
        }
         else 
         {
           item2 = Pop() ;
           item1 = Pop() ;
           switch(postfix[i]) {
            case '+' :
               Push(item1 + item2) ;
               break;
                case '-' :
                 Push(item1 - item2) ; break;
                 case '/' : 
                  Push(item1 / item2) ; break;
                    case '*' :
                     Push(item1 * item2) ; break;
           }
         }
       }
       return (stack1[top]) ;
     }
      void replaceAll(t old_item , t new_item) {
             if(IsEmpty()) {
               cout << "stack underflow" << "\n" ;
               return ;
             }
              for(int i = top ; i>=0 ;i--) {
                if(stack1[i]==old_item)
                stack1[i] = new_item ;
              }
      }
       void Reverse() {
        if(IsEmpty())
        {
          cout << "stack is empty" << endl;
          return ;
        }
         StackADT<int> *s2 = new StackADT(top+1) ;
         for(int i=top ; i>=0;i--) {
          s2->Push(stack1[i]) ;
         }
         for(int i=top ; i>=0;i--) {
             stack1[i] = s2->stack1[i] ;
         }
         delete [] s2 ;
       }
      
        char* ConvertToPrefix(char* infix) {
          char* prefix = new char [strlen(infix) + 1] ;
            int i=0 , j=0;
             while(infix[i] !='\0') {
              if(IsOperand(infix[i])) {
                prefix[j++] = infix[i++] ;
              }
               else{
                if(Presedence(infix[i]) >= Presedence(stack1[top])) 
                 Push(infix[i++]) ;
                 else
                  prefix[j++] = Pop() ;
               }
             }
             while(!IsEmpty()) {
               prefix[j++] = stack1[top] ;
                Pop() ;
             }
             prefix[j] = '\0' ;
              return prefix ;
        }
         t Top() {
          return stack1[top] ;
         }
        int evalPre(char *pre) {
          int item1 , item2 ;
      for(int i=0 ; pre[i]!='\0' ; i++) {
       if(IsOperand(pre[i])) {
         Push(pre[i] - '0') ;
       }
        else 
        {
          item2 = Pop() ;
          item1 = Pop() ;
          switch(pre[i]) {
           case '+' :
              Push(item1 + item2) ;
              break;
               case '-' :
                Push(item1 - item2) ; break;
                case '/' : 
                 Push(item1 / item2) ; break;
                   case '*' :
                    Push(item1 * item2) ; break;
          }
        }
      }
      return (stack1[top]) ;
    }
     

   void MakeEmpty() {
    top = -1 ;
  }
        // Convert postfix expression to prefix expression
        string PostfixToPrefix(char* postfix) {
          stack<string> tempStack; // Temporary stack to store operands and intermediate results
  
          // Iterate through each character of the postfix expression
          for (int i = 0; postfix[i] != '\0'; i++) {
              char ch = postfix[i];
  
              // If the character is an operand, push it onto the stack as a string
              if (IsOperand(ch)) {
                  tempStack.push(string(1, ch)); // Convert char to string
              }
              // If the character is an operator, pop two operands, combine them with the operator, and push back
              else {
                  string operand1 = tempStack.top();
                  tempStack.pop();
                  string operand2 = tempStack.top();
                  tempStack.pop();
  
                  // Combine the operands and operator in prefix order (operator + operand2 + operand1)
                  string result = string(1, ch) + operand2 + operand1;
                  tempStack.push(result); // Push the result back onto the stack
              }
          }
  
          // The final result will be the only element left in the stack
          return tempStack.top();
      }
       // Convert prefix expression to postfix expression
    string PrefixToPostfix(char* prefix) {
      stack<string> tempStack; // Temporary stack to store operands and intermediate results

      // Iterate through the prefix expression in reverse order
      for (int i = strlen(prefix) - 1; i >= 0; i--) {
          char ch = prefix[i];

          // If the character is an operand, push it onto the stack as a string
          if (IsOperand(ch)) {
              tempStack.push(string(1, ch)); // Convert char to string
          }
          // If the character is an operator, pop two operands, combine them with the operator, and push back
          else {
              string operand1 = tempStack.top();
              tempStack.pop();
              string operand2 = tempStack.top();
              tempStack.pop();

              // Combine the operands and operator in postfix order (operand1 + operand2 + operator)
              string result = operand1 + operand2 + string(1, ch);
              tempStack.push(result); // Push the result back onto the stack
          }
      }

      // The final result will be the only element left in the stack
      return tempStack.top();
     }
  };
  
 
  
int main() {
    FOI () ;
    StackADT<int> stackADT(100); // Create a stack of size 100

    char postfix[] = "ABC*+D/"; // Example postfix expression
    string prefix = stackADT.PostfixToPrefix(postfix);

    cout << "Postfix Expression: " << postfix << endl;
    cout << "Prefix Expression: " << prefix << endl;
    char prefix2 [] = "/+A*BCD";
      string  postfix2 = stackADT.PrefixToPostfix(prefix2);
      cout << "Postfix2 Expression: " << postfix2 << endl;
	return 0;
}
