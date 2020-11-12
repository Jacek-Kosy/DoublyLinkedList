#include <iostream>
size_t length(const char* cstr);
bool isLetter(char c);
char* reverse(char* cstr);
size_t words(const char* cstr);
size_t words2(const char* cstr);
char* concat(char* t, const char* s);
int main()
{
    using std::cout; using std::endl;
    char s1[] = "Alice in Wonderland";
    cout << "reverse: " << reverse(s1) << endl;
    cout << "length : " << length(s1)  << endl;

    char s2[] = " ... for (int i = 0; i < n; ++i){...} ...";
    cout << "words  : " << words(s2)  << endl;
    cout << "words2 : " << words2(s2) << endl;

    char s3[100] = "Hello";
    cout << "concat : " << concat(concat(s3, ", world"), "!") << endl;
}
size_t length(const char* cstr) {
    size_t result = 0;
    for (int i = 0; cstr[i] != '\0'; i++) {
        result++;
    }
    return result;
}
bool isLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    else
        return false;
}
char* reverse(char* cstr) {
    char* begin = &cstr[0];
    char* end = &cstr[(length(cstr) - 1)];
    for (; begin < end; begin++, end--) {
        char c = *begin;
        *begin = *end;
        *end = c;
    }
    return cstr;
}
size_t words(const char* cstr) {
    size_t result = 0;
    bool prvletter = false;
    for (int i = 0; cstr[i] != '\0'; i++) {
        if (isLetter(cstr[i])) {
            prvletter = true;
        }
        else if (!isLetter(cstr[i]) && prvletter == false) {
            continue;
        }
        else if (!isLetter(cstr[i]) && prvletter == true) {
            prvletter = false;
            result++;
        }
    }
    return result;
}
size_t words2(const char* cstr) {
    size_t result = 0;
    int counter = 0;
    bool prvletter = false;
    for (int i = 0; cstr[i] != '\0'; i++) {
        if (isLetter(cstr[i])) {
            counter++;
        }
        else if (!isLetter(cstr[i]) && counter < 2) {
            counter = 0;
        }
        else if (!isLetter(cstr[i]) && counter >= 2) {
            counter = 0;
            result++;
        }
    }
    return result;
}
char* concat(char* t, const char* s) {
    char* start = &t[length(t)];
    for (int i = 0; i < length(s); ++i) {
        start[i] = s[i];
    }
    return t;
}

