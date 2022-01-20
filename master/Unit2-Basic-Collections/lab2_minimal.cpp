#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool matchAllParens(string const& content) {
    // More verbose strategy
    
    bool matched = true;
    stack<int> openParens;
    stack<char> parenType;
    
    for (int i = 0; i < content.length(); i++) {
        char c = content[i];
        if (c == '(' || c == '[' || c == '{' || c == '<') {
            openParens.push(i);
            parenType.push(c);
        } else if (c == ')' || c == ']' || c == '}' || c == '>') {
            if (openParens.empty()) {
                cerr << "Found a closing paren '" << c << "' at " << i << " with no match" << endl;
                matched = false;
                
            } else {
                char first = parenType.top();
                char exp;
                if (first == '(') { exp = ')';}
                else if (first == '[') { exp = ']';}
                else if (first == '{') { exp = '}';}
                else { exp = '>';}
                
                if (c == exp) {
                    cout << "Found matched pair: " << openParens.top() << ", " << i << endl;
                    openParens.pop();                    
                    parenType.pop();
                } else {
                    cerr << "Mismatched pair: " << exp << " at " << openParens.top() << " vs " << c << " at " << i << endl;
                    matched = false;
                }
            }
            
        } else {
            // Not a paren - ignore it.
        }
    }
    while (!openParens.empty()) {
        cerr << "Missing closing paren for open paren " << parenType.top() << " at " << openParens.top() << endl;
        openParens.pop();
        parenType.pop();
        matched = false;
    }
    return matched;
}

bool matchAllParens(string const& content) {
    // Minimal working example
    stack<char> openParens;
    
    for (int i = 0; i < content.length(); i++) {
        char c = content[i];
        if (c == '(' || c == '[' || c == '{' || c == '<') {
            openParens.push(c);
            
        } else if (c == ')' || c == ']' || c == '}' || c == '>') {
            if (openParens.empty()) {
                return false;
                
            } else {
                char first = openParens.top();
                char exp;
                if (first == '(') { exp = ')';}
                else if (first == '[') { exp = ']';}
                else if (first == '{') { exp = '}';}
                else { exp = '>';}
                
                if (c == exp) {
                    openParens.pop();                    
                } else {
                    return false;
                }
            }
            
        } else {
            // Not a paren - ignore it.
        }
    }
    return openParens.empty();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1;
    }
    cout << matchAllParens(argv[1]) << endl;
}