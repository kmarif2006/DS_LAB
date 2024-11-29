// #include <bits/stdc++.h>
// using namespace std;

// bool is_palindrome(char *char_ptr,int str_length){
//     char *first_ptr=char_ptr;
//     char *last_ptr=char_ptr+str_length-1;
//     while(first_ptr<=last_ptr){
//         if(*first_ptr!=*last_ptr){
//             return false;
//         }
//         first_ptr++;
//         last_ptr--;
//     }
//     return true;
// }

// int main(){
//     string str;
//     char * char_ptr;
//     cout<<"Enter a string: ";
//     cin>>str;
//     int str_length=str.length();
//     char charArray[str_length+1];
//     char_ptr=strcpy(charArray,str.c_str());
//     if(is_palindrome(char_ptr,str_length)){
//         cout<<"Entered string is a palindrome";
//     }
//     else{
//         cout<<"Entered string is not a palindrome";
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

bool palindrome(string &str) {
    auto start = str.begin();
    auto end = str.end() - 1;
    
    while (start <= end) {
        if (*start != *end) {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    if (palindrome(str)) {
        cout << "Entered string is a palindrome.\n";
    } else {
        cout << "Entered string is not a palindrome.\n";
    }
    
    return 0;
}