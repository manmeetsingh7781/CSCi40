// Manmeet Singh
// This programs reads the file and sorts the data and write it into the new file in A-Z order
#include <iostream>
#include <fstream>
using namespace  std;

// Function prototypes
void readFile(string, string[]);
void createFile(string);
void writeFile(string, string);
void sort(string[], int);
int getFileSize(string);

// Program Constants 
const string FILE_NAME = "names.txt";
const int ARRAY_SIZE = getFileSize(FILE_NAME); // Assigning the value to the constant by calling the function 

int main(){
  int sorter;
  string line;
  string names[ARRAY_SIZE];
  readFile(FILE_NAME, names); // Reading the file and saving in array 
  sort(names, ARRAY_SIZE); // Sorting the array   
  // Taking words out from array and writing it into the new file 
  sorter = 0;
  while(sorter != ARRAY_SIZE){
    writeFile("sorted_names.txt", names[sorter] + "\n");
    sorter++;
    if(sorter == ARRAY_SIZE){
      cout << "Sorting has been completed."<< endl;
    }
  }
  cout << endl;
  return 0;
}

int getFileSize(string name){ // This function gets the file length
  int counter = 0;
  string line;
  fstream file;
  file.open(name);
  while (getline(file, line))
    counter+=1;
  return counter;
}

void createFile(string name) { // Creates a New file 
	fstream file(name);
	cout << "File has been created " << name << endl;
}

void writeFile(string name, string text) { // writes a file.. It takes two parameters first one is the target and second is what to write
	fstream file(name, ios::app);// ios::app this function appends the text into the file rather then erasing and writing it.	
	if (file) file << text;
	else createFile(name); // if file not found then it will create a new file
	file.close();
}

void readFile(string name, string arr[]) { // This function reads the file 
  int counter;
  string line;
  counter = 0;
  fstream file(name);
  while (getline(file, line)) {
    arr[counter] = line;// filling up the array with names from file
    counter++;
  }
  file.close();
}

void sort(string arr[], int size){ // This function sorts the array using bubble sort
 char letter; 
 int number = 0, start, y;
 string temp; 
 char smaller, bigger;
 for(start = 0; start <= size; start++){
    number++;
    // Here I am checking words pair by pair 
    for(y = 0; y < size - number; y++){
      smaller = arr[y][0]; // each first letter of word
      bigger  = arr[y+1][0];
      // switching the words in order
      if(smaller > bigger){
        temp = arr[y];
        arr[y] = arr[y+1];
        arr[y+1] = temp;
      }
    }
  }
}
