#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
  // Uncomment this block to pass the first stage
  while(true){
    cout << "$ ";
    string input;
    getline(std::cin, input);
    std::stringstream ss(input);
    if(input == "exit 0")return 0;
    string token;
    vector<string> tokens;
    while(ss>>token){
      tokens.push_back(token);
    }
    if(tokens[0]=="type"){
      if(tokens[1]=="type" || tokens[1]=="echo" || tokens[1]=="exit"){
        cout<<tokens[1]<<" "<<"is a shell builtin"<<endl;
      }
      else{
        cout<<tokens[1]<<": "<<"not found"<<endl;
      }
      continue;
    }
    if(tokens[0]=="echo"){
      for(int i = 1; i<(int)tokens.size()-1; i++){
        cout<<tokens[i]<<" ";
      }
      cout<<tokens[(int)tokens.size()-1]<<endl;
      continue;
    }
    cout<<input<<": command not found"<<endl;
  }
}
