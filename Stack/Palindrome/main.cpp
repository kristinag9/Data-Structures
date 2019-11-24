#include <iostream>
#include <stack>

bool isPalindrome(const std::string& word)
{
    bool isPali = true;
    std::stack<char> reversed;
    for(unsigned i = 0; i < word.size(); i++)
    {
        reversed.push(word[i]);
    }

    for(unsigned i = 0; i < word.size(); i++)
    {
        if(reversed.top() != word[i])
        {
            isPali = false;
            break;
        }
        reversed.pop();
    }
    return isPali;
}

int main()
{
    std::cout << std::boolalpha << isPalindrome("abcdba") << "\n";
    std::cout << std::boolalpha << isPalindrome("aabbaa") << "\n";

    return 0;
}
