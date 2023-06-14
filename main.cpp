#include <iostream>
#include <cstring>

using namespace std;
int main() {
  cout << "hello world" << endl;
  cout << "simplified to use an ajacency table" << endl;
  int adj[20][20];
  char names[20][80];
  for(int a = 0; a < 20; a++) {
    for(int b = 0; b < 20; b++) {
      adj[a][b] = -1;
    }
  }
  
  bool quit = false;
  //loop
  while(quit == false) {
    //ask user inpu

    char input[80];
    cin.getline(input, 80);
    if (strcmp(input, "QUIT") == 0) {
      quit = true;
    }
    if (strcmp(input, "HELP") == 0 ||
	strcmp(input, "Help") == 0 ||
	strcmp(input, "help") == 0) {
      cout << "Commands are:" << endl;
      cout << "Add Vertex" << endl;
      cout << "Add Edge" << endl;
      cout << "Remove Vertex" << endl;
      cout << "Remove Edge" << endl;
      cout << "Find Shortest Path" << endl;
      cout << "QUIT" << endl;
    }
    if (strcmp(input, "PRINT") == 0) {
      cout << "Print" << endl;
      for(int a = 0; a < 20; a++) {
	for(int b = 0; b < 20; b++) {
	  cout << adj[a][b] << " ";
	}
	cout << endl;
      }
    }
    if (strcmp(input, "Add Vertex") == 0 || strcmp(input, "AV") == 0) {
      cout << "A V" << endl;
      //find id
      cout << "what is the name id of the vertex you want to add?" << endl;
      char newid[80];;
      cin.getline(input, 80);
      //check that is is unique ID
      //adj + names
      bool pass = true;
      for (int a = 0; a < 20; a++) {
	if (strcmp(names[a]) == 1) {
	  cout << "cant be a duplicate name" << endl;
	  pass = false;
	}
      }
      if (pass == true) {
	cout << "hi" << endl;
      }

      
    if (strcmp(input, "Add Edge") == 0 || strcmp(input, "AE") == 0) {
      cout << "A E" << endl;
      //figure out what edge (add two nodes it is connecting)
      //crate cpy of find node that returns node
      int a = 0;
      cout << "what is the id of the first node it connects to?" << endl;
      cin >> a;
      int b = 0;
      cout << "what is the id of the second node it connects to?" << endl;
      cin >> b;
      cout << "what is the length of the edge?" << endl;
      int c = 0;
      cin >> c;
      //find it



      //check that both nodes exist
            
      //call add edge

    }
    if (strcmp(input, "Remove Vertex") == 0 || strcmp(input, "RV") == 0) {
      cout << "R V" << endl;
      cout << "what is the id of the vertex?" << endl;
      int num = 0;
      cin >> num;
      
      //find it

      //go call remove on all edges attached to it

	//go cpy search to look for any one sided ones 
	//lets just call remove on it there


	//then delete it

      }
    }
    if (strcmp(input, "Remove Edge") == 0 || strcmp(input, "RE") == 0) {
      cout << "R E" << endl;
      //fnd it
      //same as adding here
      int a = 0;
      cout << "what is the id of the first node it connects to?" << endl;
      cin >> a;
      int b = 0;
      cout << "what is the id of the second node it connects to?" << endl;
      cin >> b;
      //find it
      
      //check that both nodes exist
      
      //now remove it
    }
    if (strcmp(input, "Find Shortest Path") == 0) {
      int thing1;
      int thing2;
      cout << "Enter the first Node" << endl;
      cin >> thing1;
      cout << "Enter the second Node" << endl;
      cin >> thing2;
      
      cout << thing1 << " to " << thing2 << endl;
    }
    
  } 
}
