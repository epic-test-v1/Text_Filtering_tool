#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool caseInsensitiveCompare(const string &text, const string &pattern, size_t pos) {
    if (pos + pattern.size() > text.size()) return false;
    for (size_t i = 0; i < pattern.size(); ++i) {
        if (tolower(text[pos + i]) != tolower(pattern[i])) return false;
    }
    return true;
}

void filterText(string& text, const string& filter, bool caseSensitive) {
    size_t lastPos = 0;
    
    while (true) {
        size_t pos = (caseSensitive) ? text.find(filter, lastPos) : string::npos;
        
        if (!caseSensitive) {
            for (size_t i = lastPos; i < text.size(); ++i) {
                if (caseInsensitiveCompare(text, filter, i)) {
                    pos = i;
                    break;
                }
            }
        }

        if (pos == string::npos) break;
        
        text.erase(pos, filter.size());
        lastPos = pos;
    }
}

int main() {
    string text, filterString;
    char caseChoice;
    
    cout << "Enter some text:" << endl;
    getline(cin, text);

    cout << "Enter the text to be filtered:" << endl;
    getline(cin, filterString);

    cout << "Case-sensitive removal? (y/n): ";
    cin >> caseChoice;
    bool caseSensitive = (caseChoice == 'y');

    filterText(text, filterString, caseSensitive);

    cout << "Filtered text: " << text << endl;
    return 0;
}
