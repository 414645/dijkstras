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
  for(int a = 0; a < 20; a++) {
    names[a][0] = ' ';
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
	if(names[a][0] != ' ') {
	  bool proceed = true;
	  for(int b = 0; b < 80; b++) {
	    if (proceed == true) {
	      cout << names[a][b];
	    }
	    if (names[a][b] == '\0') {
	      proceed = false;
	    }
	  }
	  cout << ": ";
	}
	else {
	  cout << "   : ";
	}
	  
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
      char newid[80];
      cin.getline(newid, 80);
      //check that is is unique ID
      //adj + names
      bool pass = true;
      for (int a = 0; a < 20; a++) {
	if (strcmp(newid, names[a]) == 1) {
	  cout << "cant be a duplicate name" << endl;
	  pass = false;
	}
      }
      if (pass == true) {
	//now we add it
	bool done = false;
	for (int a = 0; a < 20; a++) {
	  if (done == false) {
	    if (names[a][0] == ' ') {
	      //add it here
	      //this method of rewiting a char array is stupid
	      //but i dont care
	      //also print ingones 
	      for (int b = 0; b < 80; b++) {
		names[a][b] = newid[b];
	      }
	      done = true;
	    }
	  }
	}
      }
    }
    
    if (strcmp(input, "Add Edge") == 0 || strcmp(input, "AE") == 0) {
      cout << "A E" << endl;
      //figure out what edge (add two nodes it is connecting)
      //crate cpy of find node that returns node
      char a[80];
      char b[80];
      for (int z = 0; z < 80; z++) {
	a[z] = ' ';
	b[z] = ' ';
      }
      cout << "what is the id of the first node it connects to?" << endl;
      cin.getline(a, 80);
      cout << "what is the id of the second node it connects to?" << endl;
      cin.getline(b, 80);
      cout << "what is the length of the edge?" << endl;
      int c = 0;
      cin >> c;
      //find it
      int first = -1;
      int second =  -1;
      for (int z = 0; z < 20; z++) {
	//cout << "a:" << a << endl;;
	//cout << "n:" << names[z] << endl;
	//strcmp is not working propery it says fo != fo
	//if (strcmp(a, names[z]) == 1) {
        if (a[0] == names[z][0]) {
	  cout << z << endl;
	  first = z;
	}
      }
      for (int z = 0; z < 20; z++) {
	//if (strcmp(b, names[z]) == 1) {
	if (b[0] == names[z][0]) {
	  second = z;
	}
      }
      
      //check that both nodes exist
      if(first != -1 && second != -1) {
	//add edge
	adj[first][second] = c;
        adj[second][first] = c;
      }
      else {
	cout << "please check your spelling" << endl;
      }
    }
    if (strcmp(input, "Remove Vertex") == 0 || strcmp(input, "RV") == 0) {
      cout << "R V" << endl;
      cout << "what is the id of the vertex?" << endl;
      
      //find it

      //go call remove on all edges attached to it
      //since this is a table just scrub collom and row of id
      //this is basicly add in reverse

      char newid[80];
      cin.getline(newid, 80);
      //check that is is there
      bool pass = false;
      for (int a = 0; a < 20; a++) {
	if (strcmp(newid, names[a]) != 1) {
	  pass = true;
	}
      }
      int temp = -1;
      if (pass == true) {
	//now we find it
	bool done = false;
	for (int a = 0; a < 20; a++) {
	  if (done == false) {
	    //cout << names[a][0] << ":" << newid[0] << endl;
	    
	    if (names[a][0] == newid[0]) {
	      //cout << "a:" << a <<  endl;
	      //del it here
	      //also save a
	      names[a][0] = ' ';
	      temp = a;
	    }
	  }
	}
      }
      //cout << "hi" << endl;
      if (temp != -1) {
	for (int a = 0; a < 20; a++) {
	  adj[a][temp] = -1;
	  adj[temp][a] = -1;
	}
      }
      
      
    }
    if (strcmp(input, "Remove Edge") == 0 || strcmp(input, "RE") == 0) {
      cout << "R E" << endl;
      char a[80];
      char b[80];
      for (int z = 0; z < 80; z++) {
	a[z] = ' ';
	b[z] = ' ';
      }
      //fnd it
      //same as adding here
      cout << "what is the id of the first node it connects to?" << endl;
      cin.getline(a, 80);
      cout << "what is the id of the second node it connects to?" << endl;
      cin.getline(b, 80);
      //find it

      //check that both nodes exist
      //now remove it
      //reverse of adding edges

      int first = -1;
      int second =  -1;
      for (int z = 0; z < 20; z++) {
	//cout << "a:" << a << endl;;
	//cout << "n:" << names[z] << endl;
	//strcmp is not working propery it says fo != fo
	//if (strcmp(a, names[z]) == 1) {
        if (a[0] == names[z][0]) {
	  cout << z << endl;
	  first = z;
	}
      }
      for (int z = 0; z < 20; z++) {
	//if (strcmp(b, names[z]) == 1) {
	if (b[0] == names[z][0]) {
	  second = z;
	}
      }
      
      //check that both nodes exist
      if(first != -1 && second != -1) {
	//add edge
	adj[first][second] = -1;
        adj[second][first] = -1;
      }
      else {
	cout << "please check your spelling" << endl;
      }

      
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
