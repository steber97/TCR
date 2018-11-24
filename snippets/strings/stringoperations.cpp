//first line is skipped
#include <ctype.h> // no equivalent C++ version...
#include <fstream>
#include <string.h>

//usefull functions
int isvowel(char ch) { // make sure ch is in lowercase
  char vowel[6] = "aeiou";
  for (int j = 0; vowel[j]; j++)
    if (vowel[j] == ch)
      return 1;
  return 0;
}
tolower(str[i]); toupper(str[i]); isdigit(str[i]); isalpha(str[i]);

string a; a.c_str(); //convert c++ string to c char*

string a = cin.getline();

int startposition = 42;
n = s.find("is", startposition);

char str[];
vector<string> tokens;
map<string, int> freq;
for (char *p = strtok(str, " ."); p; p = strtok(NULL, " .")) {
  tokens.push_back(p); // casting from C string to C++ string is automatic
  freq[p]++;
}
