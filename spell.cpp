#include <iostream>
#include <fstream>
#include <algorithm>
#include <conio.h>
using namespace std;
char lower_alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int incorrectArrangement(string input,string wd)
{
    string line;
    int found = 0;
    ifstream words (wd);
    if (words)
    {
        while(getline(words,line))
        {
            string Xinput = input, Ninput,  Tinput, Tline, Nline, Xline = line;
            int len = Xinput.size(), flen = line.size();
            if (len == flen)
            {
                for (int i=1; i<Xinput.length(); i++)
                    Ninput.push_back(input[i]);
                for (int i = 1; i < flen; i++)
                    Nline.push_back(Xline[i]);
                Xinput.resize(1);
                Xline.resize(1);
                sort(Nline.begin(),Nline.end());
                sort(Ninput.begin(), Ninput.end());
                Tinput = Xinput + Ninput;
                Tline = Xline + Nline;
                if (Tinput == Tline)
                {
                    found = 1;
                    cout<<line<<endl;
                    break;
                }
            }
        }
        words.close();
    }
    else
    {
        cout<<endl<<"Unexpected error occurred......."<<endl;
    }
    return found;
}

int exchangedCharacters (string input,string wd)
{
    string line, Xinput;
    int found = 0;
    ifstream words (wd);
    if (words)
    {
        while (getline(words,line))
        {
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = len-1; i >= 0 ; i--)
                {
                    Xinput = input;
                    Xinput[i] = lower_alpha[0];
                    for (int j=0; j<26; j++)
                    {
                        if (Xinput == line)
                        {
                            found = 1;
                            cout<<line<<endl;
                            break;
                        }
                        Xinput[i] = lower_alpha[j];
                    }
                    if (found == 1 ) break;
                    else continue;
                }
            }
        }
        words.close();
    }
    else cout<<"\nUnexpected error occurred"<<endl;
    return found;
}

int missingCharacter (string input,string wd)
{
    string Xinput, line, Tinput, Tline, Xline;
    int found = 0;
    ifstream words (wd);
    if (words)
    {
        while (getline(words,line))
        {
            for (int i = 0; i < 26; i++)
            {
                int len = input.size();
				int flen = line.size();
                Xinput = input;
                Xline = line;//data from file
                Xinput.resize(len+1,'a');
                Xinput[len] = lower_alpha[i];
                len = Xinput.size();
                string Ninput, Nline;// break the string 
                if (len == flen)
                {
                    for (int j = 1; j <=len; j++)
                        Ninput.push_back(Xinput[j]);// user data
                    for (int j = 1; j <= flen; j++)
                        Nline.push_back(Xline[j]);// file data
                    Xinput.resize(1);
                    Xline.resize(1);
                    sort(Nline.begin(),Nline.end());
                    sort(Ninput.begin(),Ninput.end());
                    Tinput = Xinput + Ninput;
                    Tline = Xline + Nline;
                    if (Tinput == Tline)
                    {
                        found = 1;
                        cout<<line<<endl;
                        break;
                    }
                }
                if (found == 1) break;
            }
            if (found == 1) break;
        }
        words.close();
    }
    else
    {
        cout<<"\nUnexpected error occurred\n";
    }
    return found;
}

int extraCharacter (string input,string wd)
{
    string Xinput, line, Ninput, Tinput;
    int found = 0;
    ifstream words (wd);
    if (words)
    {
        while (getline(words,line))
        {
             int len = input.size(), flen = line.size();
             if ((len-1) == flen)
             {
                 for (int i = 1; i < len; i++)
                 {
                     Xinput = input;
                     Xinput.erase(Xinput.begin()+i);
                     if (Xinput == line)
                     {
                         found = 1;
                         cout<<line<<endl;
                         break;
                     }
                 }
             }
        }
        words.close();
    }
    else
    {
        cout<<"\nUnexpected error occurred\n";
    }
    return found;
}

int mixedExtraMissing (string input,string wd)
{
    string Xinput, line, Xline;
    int found = 0;
    ifstream words (wd);
    if (words)
    {
        while (getline(words,line))
        {
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = 1; i < len; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        Xinput = input; Xline = line;
                        Xinput.erase(Xinput.begin()+i);
                        Xinput.resize(len, 'a');
                        Xinput[len-1] = lower_alpha[j];
                        sort(Xinput.begin()+1,Xinput.end());
                        sort(Xline.begin()+1,Xline.end());
                        if (Xinput == Xline)
                        {
                            found = 1;
                            cout<<line<<endl;
                            break;
                        }
                    }
                    if (found == 1) break;
                }
                if (found == 1) break;
            }
        }
        words.close();
    }
    return found;
}
void line (int a, char b){
	for(int i=0;i<a;i++){
		cout<<b;
	}
}
void menu(){
	line(10,' ');
	line(10,'-');
	cout<<" Spelling Checker ";
	line(10,'-');
	cout<<"\n\n";
	line(10,' ');
	cout<<"1. British Dictionary\n";
	line(10,' ');
	
	cout<<"2. American Dictionary\n";
	line(10,' ');
	
	cout<<"3. Search History \n";
	
	line(10,' ');
	cout<<"4. Exit \n";
	line(10,' ');
	cout<<endl;
	cout<<"Select the Dictionary -->";
	
}
void mainMethod(string dic)  {    
	    string input,line;
        string wd;
        //wd="words.txt";
        wd=dic;
        int len,flen,correct=0;
        cout<<"Enter the word: "; 
		cin.ignore();
		getline(cin,input);
       //Log file write for the history purpose
	    fstream log("log_file.txt",ios::app);
        log<<input<<endl;
        len = input.length();
        for (int i=0; i < len; i++)
            input[i] = tolower(input[i]);
        ifstream words (wd);

  
        if(words)
        {
        	bool flg=false;
            while (getline(words,line))
            {
                flen = line.length();
                if (len==flen)
                {
                    if (line==input)
                    {
                        correct=1;
                    }
                    else 
					continue;
                }
                else
				 continue;
            }
            words.close();
            if (correct==1)
            {
                cout<<endl<<"Spelling is correct"<<endl;
            }
            if (correct==0)
            {
            	
                int missing = 0, extra = 0, mixed = 0, incorrect = 0, exchanged = 0;
                cout<<endl<<"Spelling is wrong. Possible right spellings are given below:- "<<endl<<endl;
                missing = missingCharacter(input,wd);
                extra = extraCharacter(input,wd);
                mixed = mixedExtraMissing(input,wd);
                incorrect = incorrectArrangement(input,wd);
                exchanged = exchangedCharacters(input,wd);
                flg=true;
                if (missing == 0 && extra == 0 && mixed == 0 && incorrect == 0 && exchanged == 0)
                {
                    cout<<endl<<"No such word exist"<<endl;
                    flg=true;
                }
                
            }
            if (flg==true){
            	char add='n';
            	cout<<"Add to diconary press y/n ";
            	cin>>add;
            	if(add=='y'|| add=='Y'){
            		fstream log(wd,ios::app);
        			log<<input<<endl;
        			
        			cout<<"\t\t\tWord added successfully!!\n";
        
				}
            	
			}
        }
        else
        {
            cout<<"Not able to open words.txt"<<endl;
        }
        cout<<endl<<"Press any key to continue..."<<endl<<endl;
        _getch();
        system("cls");
    }

int main()
{
	
    while (true) {
    abc:
		menu();
	int b=0;
	string ab;
	
	cin>>ab;
	string dic="";

	
	
		if(ab[b]>=49 &&ab[b]<=52){
			b++;
		}
		else
	{
		cout<<"\n\t\tOnly numeric values are allowed"<<endl<<endl;
		cout<<"Press any key to continue..\n";
		getch();
		system("cls");
	    goto abc;
	}	
		if(ab=="1"){
		
		dic="words.txt";
		mainMethod(dic);
		}
	else if (ab=="2"){
	
		dic="word2.txt";
		mainMethod(dic);
		}
		else if (ab=="3"){
			//log file read 
		ifstream history("log_file.txt");
		char a[200];
		history.getline(a,200,'\0');
		cout<<a;
		cout<<"Press any key to continue.....";
		getch();
		system("cls");
		menu();
		cin>>ab;
			}
		else if (ab=="4"){
			return 0;
	
			break;
		}
		else {
		cout<<"wrong output\n\nPress any key to continue...";
		getch();
			system("cls");
		
			}
			
	}
	
}


